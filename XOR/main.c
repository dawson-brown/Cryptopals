#include <stdio.h>
#include "parser.h"
#include "xor.h"

int main(int argc, char **argv){
    
    struct arguments arguments;
    arguments.args[0] = NULL;
    arguments.args[1] = NULL;
    argp_parse (&argp, argc, argv, 0, 0, &arguments);
    verify_arguments(arguments);
    
    hex_num_t hex1 = convertToHex(arguments.args[0]);
    hex_num_t hex2 = convertToHex(arguments.args[1]);

    hex_num_t xorSum = xor_sum(&hex1, &hex2);

    printf("XOR sum: ");
    for (int i=0; i<xorSum.size; i++)
        printf("%c", xorSum.num[i]);

    printf("\n");
    
    free(hex1.num);
    free(hex2.num);
    free(xorSum.num);

    return 0;
}
