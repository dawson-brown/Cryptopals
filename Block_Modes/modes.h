#include <stdlib.h>
#include <string.h>

typedef struct block_ctx {
    unsigned char *text;
    int length;
} block_ctx_t;



//block cipher modes of operation and helpers

block_ctx_t init_ciphertext(unsigned char *input, int block, int len, unsigned char **end);

block_ctx_t ecb_enc(
    unsigned char *(*cipher)(unsigned char*, unsigned char*), 
    unsigned char *state,
    unsigned char *key,
    int block_size,
    int length
);

block_ctx_t ecb_dec(
    unsigned char *(*cipher)(unsigned char*, unsigned char*), 
    block_ctx_t input,
    unsigned char *key
);

/*
void cbc_enc(unsigned char *(*cipher)(unsigned char*, unsigned char*), cbc_ctx_t state);

void cbc_dec(unsigned char *(*cipher)(unsigned char*, unsigned char*), cbc_ctx_t state);
*/