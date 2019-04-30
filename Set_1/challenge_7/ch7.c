#include "ch7.h"

unsigned char *fopen_read(char *filename)
{

    FILE * text = fopen(filename, "r");
    fseek(text, 0, SEEK_END);
    long fsize = ftell(text);
    fseek(text, 0, SEEK_SET);

    char *string = malloc(fsize);
    fread(string, 1, fsize-1, text);
    fclose(text);

    string[fsize-1] = 0;
    return string;

}

hex_t base64_decode(const unsigned char *base64, int base64_len)
{
    short padding = 0; 
    if (base64[base64_len-2]=='=') padding+=2;
    else if (base64[base64_len-1]=='=') padding ++;

	int len = ((3*base64_len)/4)-(((base64_len + 4)+padding)%4);
	hex_t hex = {.num = malloc(len), .len = len};
	unsigned char *start = hex.num;

	int buffer_count = 0;

	while (buffer_count < (base64_len-padding)){

		*start++ = (ascii_to_base64(base64[buffer_count]) << 2) ^ (ascii_to_base64(base64[++buffer_count]) >> 4);
		*start++ = (ascii_to_base64(base64[buffer_count]) << 4) ^ (ascii_to_base64(base64[++buffer_count]) >> 2);
		*start++ = (ascii_to_base64(base64[buffer_count]) << 6) ^ (ascii_to_base64(base64[++buffer_count]));
		++buffer_count;
	}

	return hex;
}

unsigned char ascii_to_base64(char a){

	unsigned char base64 = a;

	if ((base64 >= 'A') && (base64 <= 'Z'))
		return base64 - 65;
	else if ((base64 >= 'a') && (base64 <= 'z'))
		return base64 - 71;
	else if (base64 >= '0' && base64 <= '9')
		return base64 + 4;
	else if (base64 == '+')
		return 62;
	else if (base64 == '/')
		return 63;
	else if (base64 == '=')
		return 64;
	else {
		exit(0);
	}


}