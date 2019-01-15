#include "../../number_handler/number_handler.h"

//27 to included [spaces]
#define ALPHA_SIZE 27

typedef struct keyed_text {
    hex_num_t *text;
    unsigned char key;
    float cost;
} keyed_text_t;

typedef struct vigenere_text {
    char *text;
    unsigned char *key;
    int size;
} vigenere_text_t;

hex_num_t *xor_sum(hex_num_t *hex1, hex_num_t *hex2);

float total_cost(hex_num_t *text);

keyed_text_t *cipher_char_guess(hex_num_t *hex);

hex_num_t *single_byte_decrypt(hex_num_t *hex, unsigned char key);

keyed_text_t *detect_single_xor(FILE* file);

keyed_text_t *keyed_text_init();

void keyed_text_set(keyed_text_t *keyed_text, hex_num_t *hex, unsigned char key, float cost);

void free_keyed_text(keyed_text_t *text);

void free_vigenere_text(vigenere_text_t *vig);

vigenere_text_t *vigenere_init(char *hex, char *key);

void vigenere_enc(vigenere_text_t *plaintext);

void vigenere_dec(vigenere_text_t *ciphertext);
