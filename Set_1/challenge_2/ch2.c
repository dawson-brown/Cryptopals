#include "ch2.h"

unsigned char *xor_sum(const unsigned char *a, const unsigned char *b, int len)
{
    unsigned char *c = malloc(len);
    unsigned char *iter = c;
    while(--len)
        *iter++ = *a++ ^ *b++;
    
    return c;
}

void print_hex(const unsigned char *a, int len){
    while(--len)
        printf("%c", *a++);
    printf("\n");
}