#include <stdio.h>
#include "parser.h"
#include "xor.h"

int main(int argc, char **argv){
    
    struct arguments arguments;
    arguments.args[0] = NULL;
    arguments.args[1] = NULL;
    arguments.file = NULL;
    arguments.ciphertext = NULL;
    arguments.file_vigenere = NULL;
    arguments.vigenere_key = NULL;
    argp_parse (&argp, argc, argv, 0, 0, &arguments);
    

    if (arguments.ciphertext != NULL){

        hex_num_t *ciphertext = convertToHex(arguments.ciphertext);
        keyed_text_t *text = cipherCharGuess(ciphertext);

        printf("The byte used for encryption was: %c\n", text->key);
        print_hex("Decrypted text: ", text->text);

        free_keyedText(text);
        free_hexNum(ciphertext);

    } else if (arguments.file != NULL){

        FILE* file = file_open(arguments.file);

        keyed_text_t *text = DetectSingleXor(file);

        printf("The byte used for encryption was: %c\n", text->key);
        print_hex("Decrypted text: ", text->text);

        free_keyedText(text);

    } else if(arguments.file_vigenere != NULL){

        char *string = file_open_read(arguments.file_vigenere);
        vigenere_text_t *vig = VigenereInit(string, arguments.vigenere_key);
        VigenereEnc(vig);

        printf("Encrypted: ");
        for (int i=0; i<vig->size; i++)
            printf("%x", vig->text[i]);
        printf("\n");

        free_vigenere_text(vig);
        
    } else {

        hex_num_t *hex1 = convertToHex(arguments.args[0]);
        hex_num_t *hex2 = convertToHex(arguments.args[1]);

        hex_num_t *xorSum = xor_sum(hex1, hex2);

        print_hex("XOR sum: ", xorSum);
        
        free_hexNum(hex1);
        free_hexNum(hex2);
        free_hexNum(xorSum);

    }

    return 0;
}
