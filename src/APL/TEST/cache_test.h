#ifndef CACHE_TEST_H_
#define CACHE_TEST_H_
int iCacheSize,iCacheLineSize,dCacheSize,dCacheLineSize;
typedef enum pfm_type_enum
{
    PFM_TYPE_HIT_RATE_D,
    PFM_TYPE_HIT_RATE_I,
    PFM_TYPE_MAX,
} PFM_type_e;

typedef enum return_enum
{
    RETURN_OK,
    RETURN_FAIL,
    RETURN_INTPUT_INVALID,
    RETURN_MAX,
} return_e;

extern return_e PFM_start(PFM_type_e ePFMtpye);
extern return_e PFM_stop();

void cache_invalidate_d();
void cache_invalidate_i();
void cache_on();
void cache_off();
void testcode(unsigned int size);

#endif /* CACHE_TEST_H_ */

