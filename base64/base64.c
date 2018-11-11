#include "base64.h"

static char base64Dic[65] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
	'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
	'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
	'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
	'w', 'x', 'y', 'z', '0', '1', '2', '3',
	'4', '5', '6', '7', '8', '9', '+', '/'
};
 
base_64_t *Base64Encode(unsigned char* buffer, size_t length) {

	base_64_t *b64 = malloc(sizeof(base_64_t));
	int padding = ((length + 3) % 3)*2 % 3;
	int len = 4*ceil((double)length/3);
	char *start = (char*)malloc(len);
	b64->num = start;
	b64->size = len;

	int buffer_count = 0;

	while (buffer_count <= length){

		*start++ = base64Dic[buffer[buffer_count] >> 2];
		*start++ = base64Dic[((buffer[buffer_count] & ((1 << 2) - 1)) << 4) + (buffer[++buffer_count] >> 4)];
		*start++ = base64Dic[((buffer[buffer_count] & ((1 << 4) - 1)) << 2) + (buffer[++buffer_count] >> 6)];
		*start++ = base64Dic[buffer[buffer_count++] & ((1 << 6) - 1)];

	}

	//add padding
	if (padding != 0)
		*--start = '=';
	if (padding==2)
		*--start = '=';

	return b64;
}

unsigned char asciiToHex(char a){
	unsigned char hex = a;

	if (hex > DIG_LOW && hex < DIG_HIGH){
		return hex-HEX_OFFSET_DIG;
	} else if (hex > CHAR_CAP_LOW && hex < CHAR_CAP_HIGH){
		return hex-HEX_OFFSET_CHAR_CAP;
	} else if (hex > CHAR_LOW_LOW && hex < CHAR_LOW_HIGH){
		return hex-HEX_OFFSET_CHAR_LOW;
	} else {
		printf("Invalid hex character. Exiting...\n");
		exit(0);
	}
}

hex_num_t *convertToHex(char * stringNum){
	//eg. "68" -> 0x68

	int len = strlen(stringNum);
	int hexLen = len % 2 == 0 ? len/2 : len/2 + 1;

	unsigned char a,b;

	hex_num_t *hexNum = malloc(sizeof(hex_num_t));
	unsigned char *start = (unsigned char*)malloc(hexLen);
	hexNum->num = start;
	hexNum->size = hexLen;

	for(int i=0; i<len-1; i+=2){

		a = asciiToHex(stringNum[i]);
		b = asciiToHex(stringNum[i+1]);

		a = a << 4;
		*start = a+b;

		start++;
	}

	//special last case for odd len
	if (len % 2 != 0){
		a = asciiToHex(stringNum[len-1]);
		a = a << 4;
		*start = a;
	}


	return hexNum;
}