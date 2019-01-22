#include "ch5.h"

const static char *text = "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal";
const static char *key = "ICE";

int main()
{
    int len = strlen(text);
    unsigned char *ciphertext = malloc(len);
    repeated_xor(text, ciphertext,len, key);

    print_hex(text, len);
    print_hex(ciphertext, len);

    free(ciphertext);
}