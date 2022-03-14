/**
 ****************************************************************************************
 *
 * @file co_rbuf.h
 *
 * @brief
 *
 * @author WeighSong
 *
 *
 * Copyright (C), 2017 - 2018, KT Micro,Inc.
 *
 ****************************************************************************************
 */

#ifndef _CO_RBUF_H_
#define _CO_RBUF_H_

#include <stdbool.h>
#include <stdint.h>
#include "arch.h"
#include "co_math.h"

typedef uint16_t rbuf_size_t;

typedef enum co_rbuf_res_enum {
    RBUF_FAIL,
    RBUF_OK,
} rbuf_res_t;

typedef struct _co_rbuf_stru {
    uint8_t     *mem;          /* Memory */
    rbuf_size_t wr_pos;        /* Writen Position */
    rbuf_size_t rd_pos;        /* Read Position */
    rbuf_size_t msize;         /* Buffer Size */
    rbuf_size_t blk_size;      /* Block Size */
    uint32_t    st;            /* status, bit0 NOT empty, bit 1 full */
} co_rbuf_t;

#define RBUF_STBIT_NOT_EMPTY            (CO_BIT(0))
#define RBUF_STBIT_FULL                 (CO_BIT(1))

__INLINE bool co_rbuf_is_full(co_rbuf_t *rbuf)
{
    ASSERT_ERR(rbuf);
    return  (rbuf->st & RBUF_STBIT_FULL ? true : false);
}

__INLINE bool co_rbuf_is_empty(co_rbuf_t *rbuf)
{
    ASSERT_ERR(rbuf);
    return (rbuf->st & RBUF_STBIT_NOT_EMPTY ? false : true);
}

/**
 ****************************************************************************************
 * Retrieve max number of blocks that counld be written in buffer.
 *
 * @param       rbuf        Ring buffer instance
 *
 * @return      Max blocks number
 *
 ****************************************************************************************
 */
__INLINE rbuf_size_t co_rbuf_max_blocks_get(co_rbuf_t *rbuf)
{
    ASSERT_ERR(rbuf);
    return (rbuf->msize / rbuf->blk_size);
}

__INLINE void *co_rbuf_wr_ptr_get(co_rbuf_t *rbuf)
{
    ASSERT_ERR(rbuf);
    return (rbuf->mem + rbuf->wr_pos);
}

__INLINE void *co_rbuf_rd_ptr_get(co_rbuf_t *rbuf)
{
    ASSERT_ERR(rbuf);
    return (rbuf->mem + rbuf->rd_pos);
}

__INLINE void *co_rbuf_pos_one_add(co_rbuf_t *rbuf, void *ptr)
{
    ASSERT_ERR(rbuf);
    return (rbuf->mem + co_wrap_add(((uint8_t *)ptr - rbuf->mem), rbuf->blk_size, rbuf->msize));
}

__INLINE void *co_rbuf_pos_add(co_rbuf_t *rbuf, void *ptr, rbuf_size_t blk_num)
{
    ASSERT_ERR(rbuf);
    return (rbuf->mem + co_wrap_add(((uint8_t *)ptr - rbuf->mem), (blk_num * rbuf->blk_size), rbuf->msize));
}

/**
 ****************************************************************************************
 * Initializes ring buffer on the allocated memory.
 *
 * @param       rbuf           Pointer of allocated memory
 * @param       mem_size       Total memory size
 * @param       blk_size       Block size
 *
 * @return      Ring buffer instance.
 *
 ****************************************************************************************
 */
co_rbuf_t *co_rbuf_init(void *mem, rbuf_size_t mem_size, rbuf_size_t blk_size);
void rbuf_init(co_rbuf_t *rbuf, void *mem, rbuf_size_t mem_size, rbuf_size_t blk_size);


/**
 ****************************************************************************************
 * Get number of blocks written in buffer.
 *
 * @param       rbuf        Ring buffer instance
 *
 * @return      Number of blocks written.
 *
 ****************************************************************************************
 */
rbuf_size_t co_rbuf_written_blocks_get(co_rbuf_t *rbuf);
rbuf_size_t co_rbuf_free_blocks_get(co_rbuf_t *rbuf);
void *co_rbuf_rd_ref(co_rbuf_t *rbuf, rbuf_size_t *blk_num);
rbuf_res_t co_rbuf_rd_move(co_rbuf_t *rbuf, rbuf_size_t blk_num);
rbuf_res_t co_rbuf_wr_move(co_rbuf_t *rbuf, rbuf_size_t blk_num);
rbuf_size_t co_rbuf_write(co_rbuf_t *rbuf, void *blk, rbuf_size_t blk_num);
rbuf_size_t co_rbuf_read(co_rbuf_t *rbuf, void *blk, rbuf_size_t blk_num);

#endif /* #ifndef _CO_RBUF_H_ */
