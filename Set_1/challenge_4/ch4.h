#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void dec(const unsigned char *a, unsigned char *b, const unsigned char key, int len);

float string_cost(const unsigned char *string, int len);

unsigned char *cipher_char_guess(const unsigned char *hex, int len, unsigned char *key);

unsigned char *detect_single_xor(FILE* file, int len, unsigned char *key);

void print_hex(const unsigned char *a, int len);