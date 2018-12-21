#include "parser.h"

const char *argp_program_version = "argex 1.0";

const char *argp_program_bug_address = "<bug-gnu-utils@gnu.org>";

enum parser_opts {
    //options with short names
    encode = 'e',
    encode_group = 0,

    //options with long names only
    decode = 'd',
    decode_group = 1

};

struct argp_option options[] =
{
  {"encode", encode, "The hex number to encode in base 64", 0, 0, encode_group},
  {"decode", decode, "The base 64 number to decode to hex", 0, 0, decode_group},
  {0}
};

error_t parse_opt (int key, char *arg, struct argp_state *state)
{
    struct arguments *arguments = state->input;
    switch (key)
    {
        case encode:
            arguments->hex = arg;
            return ARGP_KEY_SUCCESS;
        case decode:
            arguments->base64 = arg;
            return ARGP_KEY_SUCCESS;
        case ARGP_KEY_ARG:
            argp_usage (state);
            break;

        case ARGP_KEY_END:
            if (state->arg_num != 0)
            /* No optionless arguments. accepted*/
            argp_usage (state);
            break;

        default:
            return ARGP_ERR_UNKNOWN;
    }
    return 0;
}
