#include <openssl/bio.h>
#include <openssl/buffer.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

int main(int argc, char **argv)
{
	struct arguments arguments;
    argp_parse (&argp, argc, argv, 0, 0, &arguments);
    char *input = arguments.hex;
    
    //TODO: convert hex to base64

    return 0;
}
