#include "ch1.h"

const char base64_dic[65] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
	'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
	'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
	'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
	'w', 'x', 'y', 'z', '0', '1', '2', '3',
	'4', '5', '6', '7', '8', '9', '+', '/',
	'='
};

void base64_init(base_64_t *base64, int len)
{
	base64->num = (unsigned char*)malloc(len);
	base64->len = len;
}

base_64_t base64_encode(const unsigned char *hex, int hex_len)
{
	short padding = ((hex_len + 3) % 3)*2 % 3;
	base_64_t b64;
    base64_init(&b64, (4*hex_len)/3);
	unsigned char *start = b64.num;

	while (--hex_len)
    {
		*start++ = *hex >> 2;
		*start++ = ((*hex & ((1 << 2) - 1)) << 4) ^ (*++hex >> 4);
		*start++ = ((*hex & ((1 << 4) - 1)) << 2) ^ (*++hex >> 6);
		*start++ = *hex++ & ((1 << 6) - 1);
	}

	if (padding > 0){
		*--start = 64;
		if (padding==2)
			*--start = 64;
	}

	return b64;
}