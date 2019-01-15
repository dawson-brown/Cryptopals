#include <stdio.h>
#include "ch3.h"

static unsigned char *ciphertext = "\x1b\x37\x37\x33\x31\x36\x3f\x78\x15\x1b\x7f\x2b\x78\x34\x31\x33\x3d\x78\x39\x78\x28\x37\x2d\x36\x3c\x78\x37\x3e\x78\x3a\x39\x3b\x37\x36";
const static int len = 35; 

int main()
{
    unsigned char key='\0';
    unsigned char *text = cipher_char_guess(ciphertext, len, &key);

    printf("The byte used for encryption was: %c\n", key);
    print_hex(text, len);

    free(text);
}