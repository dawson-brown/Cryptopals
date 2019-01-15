#include <stdio.h>
#include "../../file_handler/file_handler.h"
#include "../../crypto_handler/XOR/xor.h"

int main(){

    char *filename = "text";
    char *key = "ICE";

    char *string = file_open_read(filename);
    vigenere_text_t *vig = vigenere_init(string, key);
    vigenere_enc(vig);

    printf("Encrypted: ");
    for (int i=0; i<vig->size; i++)
        printf("%x", vig->text[i]);
    printf("\n");

    free_vigenere_text(vig);
}