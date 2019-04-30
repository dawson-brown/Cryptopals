#include "../../AES/aes.h"
#include "../../Block_Modes/modes.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct hex {
    unsigned char *num;
    int len;
} hex_t;

unsigned char ascii_to_base64(char a);

unsigned char *fopen_read(char *filename);

hex_t base64_decode(const unsigned char *base64, int base64_len);

void print(unsigned char *text, int len);