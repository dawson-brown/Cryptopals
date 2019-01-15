#include "xor.h"

hex_num_t *xor_sum(hex_num_t *hex1, hex_num_t *hex2){
	
	int len = hex1->size < hex2->size ? hex1->size : hex2->size;
	hex_num_t *xor = hex_init(len);

	for (int i=0; i<len; i++){
		xor->num[i] = hex1->num[i] ^ hex2->num[i];
	}

	return xor;

}

float total_cost(hex_num_t *text){

	float freq[ALPHA_SIZE] = {
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

keyed_text_t *cipher_char_guess(hex_num_t *hex){

	float cost, best = __FLT_MAX__;
	hex_num_t *plaintext = hex_init(hex->size);
	keyed_text_t *keyed_text = keyed_text_init();

	for (int i=0; i<=255; i++){
		plaintext = single_byte_decrypt(hex, i);
		cost = total_cost(plaintext);
		if (cost<best){
			keyed_text_set(keyed_text, plaintext, i, cost);
			best = cost;
		}
	}

	return keyed_text;

}

hex_num_t *single_byte_decrypt(hex_num_t *hex, unsigned char key){

	int len = hex->size;
	hex_num_t *plaintext = hex_init(len);
	unsigned char *start = plaintext->num;

	for (int i=0; i<len; i++){
		*start++ = hex->num[i] ^ key;
	}

	return plaintext;

}

keyed_text_t *detect_single_xor(FILE* file){

	int len = 60;
	hex_num_t *hex_line = hex_init(len);
	keyed_text_t *key_line = keyed_text_init();
	keyed_text_t *guess = keyed_text_init();
	char line[len + 2];
	float best = __FLT_MAX__;

	while (fgets(line, len + 2, file)) {
		line[len] = '\0';	
		hex_line = convert_to_hex(line);
		key_line = cipher_char_guess(hex_line);
		if (key_line->cost < best){
			guess = key_line;
			best = key_line->cost;			
		}
	}


	return guess;

}

keyed_text_t *keyed_text_init(){

	return (keyed_text_t *)malloc(sizeof(keyed_text_t));
	
}

void keyed_text_set(keyed_text_t *keyed_text, hex_num_t *hex, unsigned char key, float cost){

	keyed_text->text = hex;
	keyed_text->key = key;
	keyed_text->cost = cost;

}

void free_keyed_text(keyed_text_t *text){

	free_hex_num(text->text);
	free(text);

}

void free_vigenere_text(vigenere_text_t *vig){

	free(vig->text);
	free(vig);

}

vigenere_text_t *vigenere_init(char *msg, char *key){

	vigenere_text_t *text = (vigenere_text_t *)malloc(sizeof(vigenere_text_t));

	text->key = key;
	text->text = msg;
	text->size = strlen(msg);

	return text;

}

void vigenere_enc(vigenere_text_t *plaintext){

	int len = plaintext->size;
	int keylen = strlen(plaintext->key);
	for (int i=0; i<len; i++){
		plaintext->text[i] ^= plaintext->key[i % keylen];
	}

}

void vigenere_dec(vigenere_text_t *ciphertext){

	vigenere_enc(ciphertext);

}

