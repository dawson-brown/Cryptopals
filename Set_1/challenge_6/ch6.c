#include "ch6.h"

//pre-condition: strlen(str1) == strlen(str2)
int hamming_distance(char *str1, char *str2){

    char *char1 = str1, *char2 = str2;
    unsigned char hamming_char;
    int hamming_str = 0;

    while (*char1 != '\0'){

        for(hamming_char = *char1 ^ *char2; hamming_char != '\0'; hamming_char >>= 1){
            if (hamming_char & 1)
                hamming_str++;
        }

        char1++;
        char2++;

    }

    return hamming_str;
}