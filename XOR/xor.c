#include "xor.h"

hex_num_t xor_sum(hex_num_t *hex1, hex_num_t *hex2){

	if (hex1->size != hex2->size)
		exit(0);
	
	int len = hex1->size;
	hex_num_t xor;
	unsigned char *start = (unsigned char*)malloc(len);
	xor.num = start;
	xor.size = len;
	int i;

	for (i=0; i<len; i++){
		*start++ = hex1->num[i] ^ hex2->num[i];
	}

	return xor;
}