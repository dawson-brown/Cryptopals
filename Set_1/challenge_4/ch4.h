#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define HEX_OFFSET_CHAR_LOW 87
#define HEX_OFFSET_CHAR_CAP 55

void dec(const unsigned char *a, unsigned char *b, const unsigned char key, int len);

float string_cost(const unsigned char *string, int len);

float cipher_char_guess(const unsigned char *hex, unsigned char *plaintext, int len, unsigned char *key);

unsigned char *detect_single_xor(FILE* file, int len, unsigned char *key);

unsigned char ascii_to_hex(unsigned char hex);

unsigned char *convert_to_hex(unsigned char *stringNum, int len);

void print_hex(const unsigned char *a, int len);