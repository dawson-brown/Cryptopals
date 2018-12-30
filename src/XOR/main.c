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

        hex_num_t *ciphertext = convert_to_hex(arguments.ciphertext);
        keyed_text_t *text = cipher_char_guess(ciphertext);

        printf("The byte used for encryption was: %c\n", text->key);
        print_hex("Decrypted text: ", text->text);

        free_keyed_text(text);
        free_hex_num(ciphertext);

    } else if (arguments.file != NULL){

        FILE* file = file_open(arguments.file);

        keyed_text_t *text = detect_single_xor(file);

        printf("The byte used for encryption was: %c\n", text->key);
        print_hex("Decrypted text: ", text->text);

        free_keyed_text(text);

    } else if(arguments.file_vigenere != NULL){

        char *string = file_open_read(arguments.file_vigenere);
        vigenere_text_t *vig = vigenere_init(string, arguments.vigenere_key);
        vigenere_enc(vig);

        printf("Encrypted: ");
        for (int i=0; i<vig->size; i++)
            printf("%x", vig->text[i]);
        printf("\n");

	free(string);
        free_vigenere_text(vig);
        
    } else {

        hex_num_t *hex1 = convert_to_hex(arguments.args[0]);
        hex_num_t *hex2 = convert_to_hex(arguments.args[1]);

        hex_num_t *xorSum = xor_sum(hex1, hex2);

        print_hex("XOR sum: ", xorSum);
        
        free_hex_num(hex1);
        free_hex_num(hex2);
        free_hex_num(xorSum);

    }

    return 0;
}
