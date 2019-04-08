#include "modes.h"


block_ctx_t init_ciphertext(unsigned char *input, int block, int len, unsigned char **end)
{

    unsigned char pad = (unsigned char)block - (len % block);
    int length = len + (pad==block ? 0 : pad);
    unsigned char *text = malloc(length * sizeof * text);
    *end = text + length;

    memcpy(text, input, len);
    if (pad != block)
        memset( (*end - pad), pad, pad);

    return (block_ctx_t){.text = text, .length = length};
    
}

block_ctx_t ecb_enc(unsigned char *(*cipher)(unsigned char*, unsigned char*), unsigned char *input, unsigned char *key, int block_size, int length)
{

    unsigned char *end;
    block_ctx_t state = init_ciphertext(input, block_size, length, &end);
    unsigned char *next = state.text;

    while (next < end){

        next = cipher(next, key);
        next++;

    }

    return state;
}

block_ctx_t ecb_dec(unsigned char *(*cipher)(unsigned char*, unsigned char*), block_ctx_t input, unsigned char *key)
{

    unsigned char *start, *end;

    start = malloc(input.length * sizeof * start);
    end = start + input.length;
    memcpy(start, input.text, input.length);
    block_ctx_t state = {.text = start, .length = input.length};

    while (start < end){

        start = cipher(start, key);
        start++;

    }

    return state;
}

/*
void cbc_enc(unsigned char *(*cipher)(unsigned char*, unsigned char*), cbc_ctx_t state){
    
    unsigned char *next = state.state;
    int i;

    while(1){

        next = cipher(next, state.key);
        next++;

    }
}
*/