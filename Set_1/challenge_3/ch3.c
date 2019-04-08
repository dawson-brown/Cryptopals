#include "ch3.h"

void dec(const unsigned char *a, unsigned char *b, const unsigned char key, int len)
{
    while(--len)
        *b++ = *a++ ^ key;
}

float string_cost(const unsigned char *string, int len)
{
    float freq[27] = 
    {
        0.1300, 0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, 0.02015, 
        0.06094, 0.06966, 0.00153, 0.03872, 0.04025, 0.02406, 0.06749,
        0.07507, 0.01929, 0.00095, 0.05987, 0.06327, 0.09256, 0.02758,
        0.00978, 0.05370, 0.00150, 0.03978, 0.00074
    };
    float cost = 0.0;

    while(--len)
    {
        if ((*string <= 'Z' && *string >= 'A') || (*string <= 'z' && *string >= 'a') || (*string == ' '))
            freq[*string++ % 32]-=(1.00/(float)len);
    }
    for (unsigned char i=0; i<27; i++) cost+=freq[i];

    return cost;
    
}

unsigned char *cipher_char_guess(const unsigned char *hex, int len, unsigned char *key)
{
    unsigned char *plaintext = malloc(len);
    unsigned char *best_plaintext = malloc(len);
    unsigned char temp_key = '\0';
    float best = __FLT_MAX__;

    do {
        dec(hex, plaintext, temp_key, len);
        float cost = string_cost(plaintext, len);
        if (cost<best)
        {
            memcpy(best_plaintext, plaintext, len);
            best = cost;
            *key = temp_key;
        }
    } while (++temp_key);
    free(plaintext);
    return best_plaintext;
}

void print_hex(const unsigned char *a, int len){
    while(--len)
        printf("%c", *a++);
    printf("\n");
}