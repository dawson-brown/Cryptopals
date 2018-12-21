#include "parser.h"

const char *argp_program_version = "argex 1.0";

const char *argp_program_bug_address = "<bug-gnu-utils@gnu.org>";

enum parser_opts {
    //options with short names
    cipher = 'c',
    cipher_group = 0,

    file = 'f',
    file_group = 1,

    vigenere = 'v',
    vigenere_group = 2
};

struct argp_option options[] =
{
  {"ciphertext", cipher, "The ciphertext XORed by a single byte", 0, "Get the ciphertext as a string", cipher_group},
  {"file", file, "The file containing the single XORed encrypted strings", 0, "Get the file name as a string", cipher_group},
  {"vigenere", vigenere, "The plaintext and key", 0, "Get the plaintext and key as strings", vigenere_group},
  {0}
};

error_t parse_opt (int key, char *arg, struct argp_state *state)
{
    struct arguments *arguments = state->input;
    switch (key)
    {
        case cipher:
            arguments->ciphertext = arg;
            return ARGP_KEY_SUCCESS;
            break;
        case file:
            arguments->file = arg;
            return ARGP_KEY_SUCCESS;
            break;
        case vigenere:
            arguments->file_vigenere = arg;
            break;
        case ARGP_KEY_ARG:
            if (state->arg_num > 2)
            /* Too many arguments. */
                argp_usage (state);
            if (arguments->file_vigenere != NULL){
                arguments->vigenere_key = arg;
                return ARGP_KEY_SUCCESS;
            }
            arguments->args[state->arg_num] = arg;
            break;
        case ARGP_KEY_END:
            if (state->arg_num != 2)
            /* Not enough arguments. */
                argp_usage (state);
            else if (strlen(arguments->args[0]) != strlen(arguments->args[1]))
                argp_usage (state);
            break;

        default:
            return ARGP_ERR_UNKNOWN;
    }

    
    return 0;
}