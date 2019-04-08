#include "ch4.h"

void dec(const unsigned char *a, unsigned char *b, const unsigned char key, int len)
{
    while(--len)
        *b++ = *a++ ^ key;
}

float string_cost(const unsigned char *string, int len)
{
    float freq[27] = 
    {
        0.1300, 0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, 0.02015, 
        0.06094, 0.06966, 0.00153, 0.03872, 0.04025, 0.02406, 0.06749,
        0.07507, 0.01929, 0.00095, 0.05987, 0.06327, 0.09256, 0.02758,
        0.00978, 0.05370, 0.00150, 0.03978, 0.00074
    };
    float cost = 0.0;

    while(--len)
    {
        if ((*string <= 'Z' && *string >= 'A') || (*string <= 'z' && *string >= 'a') || (*string == ' '))
            freq[*string++ % 32]-=(1.00/(float)len);
    }
    for (unsigned char i=0; i<27; i++) cost+=freq[i];

    return cost;
    
}

float cipher_char_guess(const unsigned char *hex, unsigned char *temp_best, int len, unsigned char *key)
{
    unsigned char *plaintext = malloc(len), temp_key = '\0';
    float best = __FLT_MAX__;

    do {
        dec(hex, plaintext, temp_key, len);
        float cost = string_cost(plaintext, len);
        if (cost<best)
        {
            best = cost;
            memcpy(temp_best, plaintext, len);
            *key = temp_key;
        }
    } while (++temp_key);
    free(plaintext);
    return best;
}

unsigned char *detect_single_xor(FILE* file, int len, unsigned char *key)
{

    unsigned char *line = malloc((len<<1)+2);
    unsigned char *hex_line = malloc(len);
    unsigned char *best_line = malloc(len), *temp_best = malloc(len);
    unsigned char trial_key;
    float best = __FLT_MAX__, cost;

    while(fgets(line, (len<<1)+2, file))
    {
        hex_line = convert_to_hex(line, len<<1);
        cost = cipher_char_guess(hex_line, temp_best, len, &trial_key);
        if (cost < best)
        {
            best = cost;
            *key = trial_key;
            memcpy(best_line, temp_best, len);
        }
    }
    free(line);
    return best_line;
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
		printf("Invalid hex character: %02x   Exiting...\n", hex);
		exit(0);
	}
}

unsigned char *convert_to_hex(unsigned char *stringNum, int len)
{
	unsigned char a,b;
	unsigned char *hex = malloc(len>>1), *start = hex;

	while (*stringNum != '\n')
    {
		a = ascii_to_hex(*stringNum++);
		b = ascii_to_hex(*stringNum++);

		a = a << 4;
		*start++ = a^b;
	}

    return hex;
}

void print_hex(const unsigned char *a, int len){
    while(--len)
        printf("%c", *a++);
    printf("\n");
}
