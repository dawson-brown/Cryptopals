#include "modes.h"
#include <stdio.h>

text_ctx_t pkcs7_padding(unsigned char *input, int block, int len){
    unsigned char pad = (unsigned char)block - (len % block);
    int length = len + (pad==block ? 0 : pad);
    input = realloc(input, length * sizeof * input);

    if (pad != block)
        memset( (input + length - pad), pad, pad);

    return (text_ctx_t){ .text = input, .length = length };
}

block_ctx_t init_block_ctx(unsigned char *input, int block, int len, unsigned char *key, int key_len)
{

    text_ctx_t text = pkcs7_padding(input, block, len);
    key_ctx_t block_key = { .key = key, .len = key_len };

    return (block_ctx_t){.data = text, .key = block_key, .block_size = block };
    
}

void ecb_enc(void (*cipher)(unsigned char*, unsigned char*), block_ctx_t input)
{

    unsigned char *next = input.data.text;
    unsigned char *end = input.data.text + input.data.length;

    while (next < end){

        cipher(next, input.key.key);
        next+=input.block_size;

    }
}

void ecb_dec(void (*cipher)(unsigned char*, unsigned char*), block_ctx_t input)
{

    unsigned char *start, *end;

    start = input.data.text;
    end = start + input.data.length;
    unsigned char block_key[input.key.len];

    while (start < end){

        memcpy(block_key, input.key.key, input.key.len);
        cipher(start, block_key);
        start+=input.block_size;

    }
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