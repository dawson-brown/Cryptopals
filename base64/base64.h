#include <openssl/bio.h>
#include <openssl/buffer.h>
#include <openssl/evp.h>
#include <string.h>

typedef struct hex_num {
	unsigned char* num;
	size_t size;
} hex_num_t;

int Base64Encode(const unsigned char *buffer, size_t length, char** b64text);

hex_num_t *convertToHex(char * stringNum);