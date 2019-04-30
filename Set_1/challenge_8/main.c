#include "ch8.h"

int main(void){

    int len = 321;
    FILE* file = fopen("text", "r");
    unsigned char *text = detect_ecb(file, 16, len);
    fclose(file);

    for (int i = 0; i<len/2; i++)
        printf("%02x",text[i]);
    printf("\n");
    return 0;
}