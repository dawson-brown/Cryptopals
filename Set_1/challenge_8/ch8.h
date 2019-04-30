#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define HEX_OFFSET_CHAR_LOW 87
#define HEX_OFFSET_CHAR_CAP 55

unsigned char *detect_ecb(FILE *file, size_t block_size, int len);

int ecb_compare(unsigned char* str, size_t block, int len);

unsigned char ascii_to_hex(unsigned char hex);

void convert_to_hex(unsigned char *stringNum, unsigned char* hex_line, int len);