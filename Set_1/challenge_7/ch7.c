#include "ch7.h"

fopen_read(char *filename)
{

    FILE * text = fopen(filename, "r");
    fseek(text, 0, SEEK_END);
    long fsize = ftell(text);
    fseek(text, 0, SEEK_SET);

    char *string = malloc(fsize + 1);
    fread(string, 1, fsize, text);
    fclose(text);

    string[fsize] = 0;
    return string;

}

unsigned char *base64_decode(const unsigned char *base64, int base64_len)
{
	
}