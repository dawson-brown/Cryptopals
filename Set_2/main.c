#include "ch9.h"
#include <stdio.h>

int main(void){
    unsigned char *input = malloc(16);
    memcpy(input, "YELLOW SUBMARINE", 16);
    text_ctx_t text = pkcs7_padding(input, 20, 16);

    for (int i=0; i<20; i++)
        printf("%02x", text.text[i]);
    printf("\n");
}