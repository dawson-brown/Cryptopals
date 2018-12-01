#include "base64.h"
#include "parser.h"

int main(int argc, char **argv)
{
	struct arguments arguments;
    argp_parse (&argp, argc, argv, 0, 0, &arguments);

    hex_num_t input = convertToHex(arguments.hex);
    base_64_t output = Base64Encode(input.num, input.size);

    free(input.num);
    
    printf("Output (base64): ");
    for (int i=0; i<output.size; i++)
        printf("%c", output.num[i]);

    printf("\n");
    
    free(output.num);

    return 0;
}
