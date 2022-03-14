#include "co_mem.h"

/*****************************内部宏定义****************************************/
#define HLEN                (sizeof(struct st_MEMPOOL))
#define MIN_BLOCK           (HLEN * 4)

/******************************数据结构定义*************************************/
struct st_MEMPOOL {                                 /* 内存池结构体 */
    struct st_MEMPOOL    *pNext;
    UINT32                len;
};


/*****************for memory malloc*************************/
UINT8 *g_pMallocMemPool;                       /* 动态分配的存储池指针 */
struct st_MEMPOOL g_MemPoolHead;       /* Memory Pool Head Node*/



void MEM_Init(void *pMemPool, UINT16 Len)
{
    if ((NULL == pMemPool) || (Len < MIN_BLOCK)) {
        return;
    }

    g_pMallocMemPool = pMemPool;        /* 指向内存池首地址的全局指针 */
    /*  Set the g_MemPoolHead->pNext point to the beginning of the pool and set
    *  the pool size.
    */
    g_MemPoolHead.pNext = (struct st_MEMPOOL *)g_pMallocMemPool;
    g_MemPoolHead.len = 0;
    /*  Set the first available link of the block in the pool to NULL (since it's the only
    *  block) and initialize the size of its data area.
    */
    ((struct st_MEMPOOL *)g_pMallocMemPool)->pNext = NULL;
    ((struct st_MEMPOOL *)g_pMallocMemPool)->len = Len - HLEN;
}

void * MEM_Malloc(uint16_t size)
{
    struct st_MEMPOOL *pCur;
    struct st_MEMPOOL *pPre;
    UINT16 sizeLeft;

    if (size & 0x0003) {
        size = (size & 0xfffc) + 4;
    }

    pPre = &g_MemPoolHead;
    pCur = pPre->pNext;

    while (1) {
        if (NULL == pCur) {
            return NULL;        /*空闲内存块链表没有可用内存*/
        }

        if (pCur->len >= size) {
            break;
        } else {
            pPre = pCur;
            pCur = pCur->pNext;
        }
    }

    sizeLeft = pCur->len - size;            /* 计算剩余内存大小 */

    if (sizeLeft < MIN_BLOCK) {             /*如果剩余内存太小，则将整个内存块从空闲链表删除*/
        /* rem. bytes too small for new block */
        pPre->pNext = pCur->pNext;
        pCur->pNext = NULL;
        return (&pCur[1]);                  /* pCur[0] : 内存控制块  pCur[1] : 真正可用内存的起始 */
    }

    sizeLeft -= HLEN;
    pCur->len = sizeLeft;
    pPre = (struct st_MEMPOOL *)(((INT8 *)(&pCur[1])) + sizeLeft);
    pPre->len = size;
    pPre->pNext = NULL;
    return (&pPre[1]);           /* SUCCESS */
}

void MEM_Free(void *pMem)
{
    /* FREE attempts to organize pPre, pMem, and pNxt so that pPre < pMem < pNxt.
    *  Then, pMem is inserted into the free list so that the list is maintained
    *  in address order.
    *
    *  FREE also attempts to consolidate small blocks into the largest block
    *  possible.  So, after allocating all memory and freeing all memory,
    *  you will have a single block that is the size of the memory pool.  The
    *  overhead for the merge is very minimal.*/
    struct st_MEMPOOL *pNxt;
    struct st_MEMPOOL *pPre;
    struct st_MEMPOOL *pCur = (struct st_MEMPOOL *)pMem;/* block to free */

    /*  If the user tried to free NULL, get out now.  Otherwise, get the address
     *  of the header of the memp block .  Then, try to locate pPre and pNxt such
     *  that pPre < pCur < pNxt.                                                       */

    if (NULL == pMem) {
        return;
    }

    pCur = &pCur[-1];                /* get address of header */
    pPre = &g_MemPoolHead;
    /*  Initialize.  pNxt = Location of first available block. */
    pNxt = pPre->pNext;

    if (NULL == pNxt) {  /* 空闲内存链表为空，直接将要释放的内存放入空闲链表 */
        g_MemPoolHead.pNext = pCur;
        return;
    }

    /*  B2. Advance pNxt Hop through the list until we find a free block that is
     *  located in memory AFTER the block we're trying to free.                */
    while (1) {
        if ((NULL == pNxt) || ((INT8 *)pNxt > (INT8 *)pCur)) {
            break;
        }

        pPre = pNxt;
        pNxt = pNxt->pNext;
    }

    /*  B3. Check upper bound. If pCur and pNxt are contiguous,
     *  merge block pNxt into block pCur.                                                              */

    if ((NULL != pNxt) &&
        (((INT8 *)pCur + pCur->len + HLEN) == (INT8 *)pNxt)) {
        pCur->len = pCur->len + pNxt->len + HLEN;
        pCur->pNext = pNxt->pNext;
    } else {
        pCur->pNext = pNxt;
    }

    /*  B4. Check lower bound. If pPre and pCur are contiguous,
     *  merge pCur into pPre.  */

    if (((INT8 *)pPre + pPre->len + HLEN) == (INT8 *)pCur) {
        pPre->len = pPre->len + pCur->len + HLEN;
        pPre->pNext = pCur->pNext;
    } else {
        pPre->pNext = pCur;
    }
}

void *MEN_Realloc(void *pOld, UINT16 size)
{
    struct st_MEMPOOL *pCur = NULL;
    struct st_MEMPOOL *pNxt = NULL;
    struct st_MEMPOOL *pPre = NULL;
    void *pNew = NULL;
    UINT16 sizeLeft;

    if (NULL == pOld) {
        return MEM_Malloc(size);
    }

    pCur = (struct st_MEMPOOL *)pOld;
    pCur = &pCur[-1];           /*find control block*/
    pPre = &g_MemPoolHead;
    pNxt = pPre->pNext;

    /*当重新申请内存小于控制块的内存大小时直接返回原内存,该内存块仍然会
     *在mem_free时释放
     */
    if (size <= pCur->len) {
        return &pCur[1];
    }

    /*搜索空闲内存链表*/
    while (1) {
        if ((NULL == pNxt) || ((INT8 *)pNxt > (INT8 *)pCur)) {
            break;
        }

        pPre = pNxt;
        pNxt = pNxt->pNext;
    }

    /* 没有处于pCur之后的可用BLOCK或者其后的可用BLOCK地址不与pCur连续
     * 或者两个块的长度和仍然没有size大时需要重新申请内存*/
    if ((((INT8 *)pCur + pCur->len + HLEN) != (INT8 *)pNxt) ||
        ((pCur->len + pNxt->len + HLEN) < size)) {
        pNew = MEM_Malloc(size);

        if (NULL == pNew) {
            return (NULL);
        }

        size = pCur->len;
        memcpy(pNew, pOld, size);
        MEM_Free(pOld);
        return pNew;
    } else { /*pCur和pNxt内存块地址连续并且两个块的大小要大于size*/
        sizeLeft = pNxt->len + pCur->len + HLEN - size;

        if (sizeLeft < MIN_BLOCK) { /*块太小，不足以成块*/
            pCur->len = pCur->len + pNxt->len + HLEN;
            pPre->pNext = pNxt->pNext;
        } else {
            pCur->len = size;
            pPre->pNext = (struct st_MEMPOOL *)((INT8 *)pCur + HLEN + size);
            pPre->pNext->pNext = pNxt->pNext;
            pPre->pNext->len = sizeLeft - HLEN;
        }

        return &pCur[1];
    }
}

int MEM_Cmp_Word(const void *buf1, const void *buf2, unsigned int cnt)
{
    unsigned int *pTmp1 = (unsigned int *)buf1;
    unsigned int *pTmp2 = (unsigned int *)buf2;
    unsigned int i;

    for (i = 0; i < cnt; i++) {
        if (*pTmp1 != *pTmp2) {
            return (*pTmp1 > *pTmp2) ? 1 : -1;
        }
    }

    return 0;
}

int MEM_Cpy_Word(unsigned int *des, const unsigned int *src, unsigned int cnt)
{
    unsigned int *pTmp1 = (unsigned int *)des;
    unsigned int *pTmp2 = (unsigned int *)src;
    unsigned int i;

    for (i = 0; i < cnt; i++) {
        (*pTmp1++ = *pTmp2++);
    }

    return cnt;
}
