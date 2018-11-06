#include "parser.h"

const char *argp_program_version = "argex 1.0";

const char *argp_program_bug_address = "<bug-gnu-utils@gnu.org>";

struct argp_option options[] =
{
  {0}
};

error_t parse_opt (int key, char *arg, struct argp_state *state)
{
    struct arguments *arguments = state->input;
    switch (key)
    {
    case ARGP_KEY_ARG:
        if (state->arg_num > 1)
        /* Too many arguments. */
            argp_usage (state);

        arguments->hex = arg;
        break;

    case ARGP_KEY_END:
        if (state->arg_num < 1 || state->arg_num > 1)
        /* Not enough arguments. */
            argp_usage (state);
    break;

    default:
        return ARGP_ERR_UNKNOWN;
    }
    return 0;
}
