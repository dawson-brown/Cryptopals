#include <stdlib.h>
#include <string.h>

typedef struct key_ctx {
    unsigned char* key;
    int len;
} key_ctx_t;

typedef struct text_ctx {
    unsigned char *text;
    int length;
} text_ctx_t;

typedef struct block_ctx {
    text_ctx_t data;
    key_ctx_t key;
    int block_size;
} block_ctx_t;

block_ctx_t init_block_ctx(unsigned char *input, int block, int len, unsigned char *key, int key_len);

void ecb_enc(
    void (*cipher)(unsigned char*, unsigned char*), 
    block_ctx_t input
);

void ecb_dec(
    void (*cipher)(unsigned char*, unsigned char*), 
    block_ctx_t input
);

/*
void cbc_enc(unsigned char *(*cipher)(unsigned char*, unsigned char*), cbc_ctx_t state);

void cbc_dec(unsigned char *(*cipher)(unsigned char*, unsigned char*), cbc_ctx_t state);
*/