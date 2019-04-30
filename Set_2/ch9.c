#include "ch9.h"

text_ctx_t pkcs7_padding(unsigned char *input, int block, int len){
    unsigned char pad = (unsigned char)block - (len % block);
    int length = len + (pad==block ? 0 : pad);
    input = realloc(input, length * sizeof * input);

    if (pad != block)
        memset( (input + length - pad), pad, pad);

    return (text_ctx_t){ .text = input, .length = length };
}