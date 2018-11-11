#include "xor.h"

hex_num_t *xor_sum(hex_num_t *hex1, hex_num_t *hex2){
	if (hex1->size != hex2->size)
		return NULL;

	*hex1->num = *hex1->num ^ *hex2->num;
	return hex1;
}