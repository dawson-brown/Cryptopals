#include <string.h>
#include <stdlib.h>
#include <stdio.h>

const char base64_dic[65];

typedef struct base_64 {
	unsigned char* num;
	size_t len;
} base_64_t;

void base64_init(base_64_t *base64, int len);

base_64_t base64_encode(const unsigned char *hex, int hex_len);