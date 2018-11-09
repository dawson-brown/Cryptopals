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

int Base64Encode(const unsigned char* buffer, size_t length, char** b64text) {
	BIO *bio, *b64;
	BUF_MEM *bufferPtr;

	b64 = BIO_new(BIO_f_base64());
	bio = BIO_new(BIO_s_mem());
	bio = BIO_push(b64, bio);

	BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);
	BIO_write(bio, buffer, length);
	BIO_flush(bio);
	BIO_get_mem_ptr(bio, &bufferPtr);
	BIO_set_close(bio, BIO_NOCLOSE);
	BIO_free_all(bio);

	*b64text=(*bufferPtr).data;

	return (0); //success
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