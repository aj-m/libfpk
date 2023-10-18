#include "fpk.h"

#include <stdio.h>

uint32_t byteswap_u32(uint32_t in) {
    // https://stackoverflow.com/a/3916163 - byte swapping with no temporary variables
    return ((in & 0xffff0000) >> 16) | ((in & 0x0000ffff) << 16);
}

int fpk_open(const char *path, FILE *out) {
    out = fopen(path, "rb");
    return (NULL == out) ? -1 : 0;
}

int fpk_readHeader(FILE *fpk, fpk_header *out) {
    fseek(fpk, 0, SEEK_SET);
    fread(out, 16, 1, fpk);
    return 0;
}

int fpk_getIndex();

#ifndef FPK_BUILD_LIB
int main() {
    char path[] = "./data/fpk/FILE_1014.fpk";
    FILE* fpk;
    fpk_header header;
    if((fpk = fopen(path, "rb")) != NULL) {
        printf("reading header\n");
        fpk_readHeader(fpk, &header);
        printf(
            "magic: %s\nfile count: %u\narchive header size: %u\nsize: %u\n",
            header.magic,
            header.lzs_n,
            header.lzs_p,
            header.size
        );
        fclose(fpk);
    }
    //uint32_t udemo = 23000;
    //printf("%8u\t%8u\n", udemo, byteswap_u32(udemo));
    //printf("%08x\t%08x\n", udemo, byteswap_u32(udemo));
    return 0;
}
#endif
