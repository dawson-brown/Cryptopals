#include "../../number_handler/number_handler.h"
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
        hex = convert_to_hex(arguments.hex);
        base64 = base64_encode(hex);
        print_base64("Output (base64): ", base64);
    } else {
        base64 = convert_to_base64(arguments.base64);
        hex = base64_decode(base64);
        print_hex("Output (hex): ", hex);
    }
    
    free_hex_num(hex);
    free_base64(base64);

    return 0;
}
