#include "ch4.h"

const static char *filename = "challenge-data";
const static int len = 30;

int main(){

    FILE* file = fopen(filename, "r");
    unsigned char key = '\0';

    unsigned char *text = detect_single_xor(file, len, &key);
    fclose(file);

    printf("The byte used for encryption was: %c\n", key);
    print_hex(text, len);

    free(text);
}