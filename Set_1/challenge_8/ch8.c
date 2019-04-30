#include "ch8.h"

unsigned char *detect_ecb(FILE *file, size_t block_size, int len)
{
    int hex_len = (len-1)/2;
    char line[len+1];
    unsigned char *match = malloc((len/2)*sizeof * match);
    unsigned char *hex_line = malloc(len/2);

    while(fgets(line, sizeof(line), file) != NULL){
        
        convert_to_hex(line, hex_line, hex_len);

        if (ecb_compare(hex_line, block_size, hex_len)==0){
            memcpy(match, hex_line, hex_len);
            break;
        }
        
        
    }

    return match;
}

int ecb_compare(unsigned char* str, size_t block, int len){
    unsigned char* end = str + len;
    unsigned char* start = str, *next;

    while (start < end){
        next = start + block;
        while (next < end){
            if (memcmp(start, next, block)==0){
                return 0;
            }
            next += block;
        }
        start += block;
    }
    return 1;
}

unsigned char ascii_to_hex(unsigned char hex)
{
	if (hex >= '0' && hex <= '9')
		return hex-'0';
	else if (hex >= 'A' && hex <= 'F')
		return hex-HEX_OFFSET_CHAR_CAP;
	else if (hex >= 'a' && hex <= 'f')
		return hex-HEX_OFFSET_CHAR_LOW;
	else {
		exit(0);
	}
}

void convert_to_hex(unsigned char *string, unsigned char* hex, int len)
{
    unsigned char* start = hex, *ascii = string;
	unsigned char a,b;

	while (--len)
    {
		a = ascii_to_hex(*ascii++);
		b = ascii_to_hex(*ascii++);

		a = a << 4;
		*start++ = a^b;
	}
}