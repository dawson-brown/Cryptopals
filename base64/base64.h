#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//ascii offsets for hex conversion
#define HEX_OFFSET_DIG 48
#define HEX_OFFSET_CHAR_LOW 87
#define HEX_OFFSET_CHAR_CAP 55

//ascii ranges for 0-9, A-F, a-f
#define DIG_LOW 47
#define DIG_HIGH 58
#define CHAR_CAP_LOW 64
#define CHAR_CAP_HIGH 71
#define CHAR_LOW_LOW 96
#define CHAR_LOW_HIGH 103

typedef struct base_64 {
	char* num;
	size_t size;
} base_64_t;

typedef struct hex_num {
	unsigned char* num;
	size_t size;
} hex_num_t;

unsigned char asciiToHex(char a);

base_64_t *Base64Encode(unsigned char *buffer, size_t length);

hex_num_t *convertToHex(char * stringNum);