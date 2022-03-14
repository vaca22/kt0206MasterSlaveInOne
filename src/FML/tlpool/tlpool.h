#ifndef _TLPOOL_H
#define _TLPOOL_H

#include "stdint.h"

#include "co_rbuf.h"

int tlpool_write(char *data, int size);
void tlpool_init(void);

#endif /* _TLPOOL_H */
