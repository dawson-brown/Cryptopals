#include "parser.h"

const char *argp_program_version = "argex 1.0";

const char *argp_program_bug_address = "<bug-gnu-utils@gnu.org>";

enum parser_opts {
    //options with short names
    arg1 = 'a',
    arg1_group = 0,

    //options with long names only
    arg2 = 0x100,
    arg2_group = 1

};

struct argp_option options[] =
{
  {"arg1", arg1, "the first argument, a char", 0, "Get a char as argument", arg1_group},
  {"arg2", arg2, 0, 0, "Set flag a flag", arg2_group},
  {0}
};

error_t parse_opt (int key, char *arg, struct argp_state *state)
{
  struct arguments *arguments = state->input;
    switch (key)
        {
        case arg1:
            arguments->arg1 = arg;
            break;
        case arg2:
            arguments->arg2 = 1;
            break;
        default:
            return ARGP_ERR_UNKNOWN;
        }
    return 0;
}
