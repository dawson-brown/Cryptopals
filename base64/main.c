#include <stdio.h>
#include <stdlib.h>
#include "base64.h"
#include "parser.h"

int main(int argc, char **argv)
{
	struct arguments arguments;
    argp_parse (&argp, argc, argv, 0, 0, &arguments);

    hex_num_t *input = convertToHex(arguments.hex);
    char* output;
    Base64Encode(input->num, input->size, &output);
    free(input);
    printf("Output (base64): %s\n", output);

    return 0;
}
