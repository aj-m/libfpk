#ifndef FPK_H
#define FPK_H

#include <stdint.h>

typedef struct {
    uint32_t flag;
    uint32_t lzs_n;
    uint32_t lzs_p;
    uint32_t size;
} fpk_header;

typedef struct {
    uint32_t placeholder;
} fpk_index;

typedef struct {
   uint32_t placeholder; 
} fpk_data;

extern int fpk_open();
extern int fpk_readHeader();
extern int fpk_getIndex();

#endif