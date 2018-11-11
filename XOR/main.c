#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

int main(int argc, char **argv){
    
    struct arguments arguments;
    arguments.args[0] = NULL;
    arguments.args[1] = NULL;
    argp_parse (&argp, argc, argv, 0, 0, &arguments);
    
    if (arguments.args[0] != NULL){
        printf("arg1: %s\n", arguments.args[0]);
    } 

    if (arguments.args[1] != NULL) {
        printf("arg1: %s\n", arguments.args[1]);
    }

    return 0;
}
