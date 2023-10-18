#ifndef FPK_H
#define FPK_H

#include <stdint.h>
#include <stdio.h>

typedef struct {
    char     magic[4]; // fpk
    uint32_t lzs_n; // file counut
    uint32_t lzs_p; // archive header size
    uint32_t size;  // size of whole file
} fpk_header;

typedef struct {
    char name[20];
    uint32_t data_p; // offset to entry
    uint32_t dst_size; // compressed size
    uint32_t src_size; // uncompressed size
} fpk_entry;

typedef struct {
    uint32_t placeholder;
} fpk_index;

extern int fpk_open(const char*, FILE*);
extern int fpk_readHeader(FILE*, fpk_header*);
extern int fpk_getIndex();

#endif
