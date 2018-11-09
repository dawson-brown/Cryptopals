#include <stdio.h>
#include "base64.h"
#include "parser.h"

int main(int argc, char **argv)
{
	struct arguments arguments;
    argp_parse (&argp, argc, argv, 0, 0, &arguments);

    hex_num_t *input = convertToHex(arguments.hex);
    char* output;
    Base64Encode(input->num, input->size, &output);

    printf("Output (hex): ");
    for (int i=0; i<input->size; i++)
        printf("%.2x", input->num[i]);

    printf("\n");
    free(input->num);
    free(input);
    
    printf("Output (base64): %s\n", output);

    return 0;
}
