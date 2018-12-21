#include "xor.h"

hex_num_t *xor_sum(hex_num_t *hex1, hex_num_t *hex2){

	if (hex1->size != hex2->size)
		exit(0);
	
	int len = hex1->size;
	hex_num_t *xor = hex_Init(len);

	for (int i=0; i<len; i++){
		xor->num[i] = hex1->num[i] ^ hex2->num[i];
	}

	return xor;

}

float totalCost(hex_num_t *text){

	float freq[27] = {
		0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, 0.02015, 
		0.06094, 0.06966, 0.00153, 0.03872, 0.04025, 0.02406, 0.06749,
		0.07507, 0.01929, 0.00095, 0.05987, 0.06327, 0.09256, 0.02758,
		0.00978, 0.05370, 0.00150, 0.03978, 0.00074, 0.1300
	};
	float cost = 0.0;
	int len=text->size;
	unsigned char character;
	int i;

	for (i=0; i<len; i++){
		character = text->num[i];
		if (character == 0x20) {
			freq[26]-=(1.00/(float)len);
		} else if ((character <= LOWERCASE_HIGH_BOUND && character >= LOWERCASE_LOW_BOUND) || (character <= UPPERCASE_HIGH_BOUND && character >= UPPERCASE_LOW_BOUND)){
			freq[(character % 32) + 1]-=(1.00/(float)len);
		}
	}

	for (i=0; i<ALPHA_SIZE; i++){
		cost += freq[i];
	}

	return cost;

}

keyed_text_t *cipherCharGuess(hex_num_t *hex){

	float cost, best;
	best = __FLT_MAX__;
	hex_num_t *plaintext = hex_Init(hex->size);
	keyed_text_t *keyed_text = keyed_textInit();

	for (int i=0; i<=255; i++){
		plaintext = SingleByteDecrypt(hex, i);
		cost = totalCost(plaintext);
		if (cost<best){
			keyed_text_set(keyed_text, plaintext, i, cost);
			best = cost;
		}
	}

	return keyed_text;

}

hex_num_t *SingleByteDecrypt(hex_num_t *hex, unsigned char key){

	int len = hex->size;
	hex_num_t *plaintext = hex_Init(len);
	unsigned char *start = plaintext->num;

	for (int i=0; i<len; i++){
		*start++ = hex->num[i] ^ key;
	}

	return plaintext;

}

keyed_text_t *DetectSingleXor(FILE* file){

	int len = 60;
	hex_num_t *hex_line = hex_Init(len);
	keyed_text_t *key_line = keyed_textInit();
	keyed_text_t *guess = keyed_textInit();
	char line[len + 2];
	float best = __FLT_MAX__;

	while (fgets(line, len + 2, file)) {
		line[len] = '\0';	
		hex_line = convertToHex(line);
		key_line = cipherCharGuess(hex_line);
		if (key_line->cost<best){
			guess = key_line;
			best = key_line->cost;			
		}
	}

	fclose(file);

	return guess;

}

keyed_text_t *keyed_textInit(){

	return (keyed_text_t *)malloc(sizeof(keyed_text_t));
	
}

void keyed_text_set(keyed_text_t *keyed_text, hex_num_t *hex, unsigned char key, float cost){

	keyed_text->text = hex;
	keyed_text->key = key;
	keyed_text->cost = cost;

}

void free_keyedText(keyed_text_t *text){

	free_hexNum(text->text);
	free(text);

}

void free_vigenere_text(vigenere_text_t *vig){

	free(vig->text);
	free(vig);

}

vigenere_text_t *VigenereInit(char *msg, char *key){

	vigenere_text_t *text = (vigenere_text_t *)malloc(sizeof(vigenere_text_t));

	text->key = key;
	text->text = msg;
	text->size = strlen(msg);

	return text;

}

FILE *file_open(char *filename){

	FILE* file = fopen(filename, "r");

	if (file != NULL){
		return file;

	} else {
		printf("Error opening file: %s. Exiting...\n", filename);
		exit(0);
	}

}

char *file_open_read(char *filename){

	FILE* file = file_open(filename);

	fseek(file, 0, SEEK_END);
	long fsize = ftell(file);
	rewind(file);

	char *string = malloc(fsize + 1);
	fread(string, fsize, 1, file);
	fclose(file);

	string[fsize] = 0;

	return string;

}

void VigenereEnc(vigenere_text_t *plaintext){

	int len = plaintext->size;
	int keylen = strlen(plaintext->key);
	for (int i=0; i<len; i++){
		plaintext->text[i] ^= plaintext->key[i % keylen];
	}

}

void VigenereDec(vigenere_text_t *ciphertext){

	VigenereEnc(ciphertext);

}

