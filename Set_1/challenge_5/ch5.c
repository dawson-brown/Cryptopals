#include "ch5.h"

void repeated_xor(const unsigned char *a, unsigned char *b, int len, const unsigned char *key)
{
    int key_len = strlen(key);
    for(int i=0; i<len; i++)
        *b++ = *a++ ^ key[i%key_len];
}

void print_hex(const unsigned char *a, int len){
    while(len--)
        printf("%02x", *a++);
    printf("\n");
}