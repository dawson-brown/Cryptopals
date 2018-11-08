#include "base64.h"

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
	//TODO: input sanitizing
	int i;
	int len = strlen(stringNum);
	unsigned char a,b;

	hex_num_t *hexNum = malloc(sizeof(hex_num_t));
	unsigned char *start = (unsigned char*)malloc(len/2);
	hexNum->num = start;
	hexNum->size = len/2;

	for(i=0; i<len-1; i+=2){
		a = stringNum[i]<97 ? stringNum[i] - 48 : stringNum[i] - 87;
		a = a << 4;
		b = stringNum[i+1]<97 ? stringNum[i+1] - 48 : stringNum[i+1]- 87;
		*start = a+b;
		start++;
	}

	return hexNum;
}