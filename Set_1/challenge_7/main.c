#include "ch7.h"

char *filename = "text";

int main(void){

    unsigned char key[BLOCK_SIZE] = "YELLOW SUBMARINE";
    char *text = fopen_read(filename);

    char *hex = base64_decode(text, strlen(text));

}