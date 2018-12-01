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
            if (state->arg_num > 2)
            /* Too many arguments. */
                argp_usage (state);

            arguments->args[state->arg_num] = arg;
            break;

        case ARGP_KEY_END:
            if (state->arg_num != 2)
            /* Not enough arguments. */
                argp_usage (state);
        break;

        default:
            return ARGP_ERR_UNKNOWN;
    }

    return 0;
}

void verify_arguments(struct arguments arguments){
    if (strlen(arguments.args[0]) != strlen(arguments.args[1])){
        printf("Arguments must be of equal length. Exiting...\n");
        exit(0);
    }
}