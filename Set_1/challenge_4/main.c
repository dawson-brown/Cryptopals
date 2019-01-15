#include <stdio.h>
#include "ch4.h"

const static char *filename = "challenge-data";
const static int len = 60;

int main(){

    FILE* file = fopen(filename, "r");
    unsigned char key = '\0';

    unsigned char *text = detect_single_xor(file, &key);
    fclose(file);

    printf("The byte used for encryption was: %c\n", key);
    print_hex("Decrypted text: ", text);

    free(text);
}