#include <stdlib.h>
#include <string.h>

typedef struct text_ctx {
    unsigned char *text;
    int length;
} text_ctx_t;

text_ctx_t pkcs7_padding(unsigned char *input, int block, int len);