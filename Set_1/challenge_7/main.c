#include "ch7.h"

char *filename = "text";

int main(void){

    char *input = fopen_read(filename);
    unsigned char key[BLOCK_SIZE] = "YELLOW SUBMARINE";
    key_expand(key);

    hex_t hex = base64_decode(input, strlen(input));
    block_ctx_t text = {.data = { .text = hex.num, .length = hex.len }, .key = {.key = key, .len = BLOCK_SIZE}, .block_size = BLOCK_SIZE };

    ecb_dec(aes_dec, text);

    print(text.data.text, text.data.length);
}

void print(unsigned char *text, int len){
    while (len--)
        printf("%c", *text++);
}