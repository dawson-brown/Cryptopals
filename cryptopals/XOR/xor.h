#include "../base64/base64.h"

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

float totalCost(hex_num_t *text);

keyed_text_t *cipherCharGuess(hex_num_t *hex);

hex_num_t *SingleByteDecrypt(hex_num_t *hex, unsigned char key);

keyed_text_t *DetectSingleXor(FILE* file);

keyed_text_t *keyed_textInit();

void keyed_text_set(keyed_text_t *keyed_text, hex_num_t *hex, unsigned char key, float cost);

void free_keyedText(keyed_text_t *text);

void free_vigenere_text(vigenere_text_t *vig);

vigenere_text_t *VigenereInit(char *hex, char *key);

FILE *file_open(char *filename);

char *file_open_read(char *filename);

void VigenereEnc(vigenere_text_t *plaintext);

void VigenereDec(vigenere_text_t *ciphertext);
