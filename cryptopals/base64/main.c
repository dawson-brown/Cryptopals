#include "base64.h"
#include "parser.h"

int main(int argc, char **argv)
{
	struct arguments arguments;
    arguments.base64 = NULL;
    arguments.hex = NULL;
    argp_parse (&argp, argc, argv, 0, 0, &arguments);

    hex_num_t *hex;
    base_64_t *base64;
    
    if (arguments.hex != NULL){
        hex = convertToHex(arguments.hex);
        base64 = Base64Encode(hex);
        print_base64("Output (base64): ", base64);
    } else {
        base64 = convertToBase64(arguments.base64);
        hex = Base64Decode(base64);
        print_hex("Output (hex): ", hex);
    }
    
    free_hexNum(hex);
    free_base64(base64);

    return 0;
}
