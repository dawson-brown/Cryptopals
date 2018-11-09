#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

int main(int argc, char **argv){
    
    struct arguments arguments;
    arguments.arg1 = NULL;
    arguments.arg2 = 0;
    argp_parse (&argp, argc, argv, 0, 0, &arguments);
    
    if (arguments.arg1 != NULL){
        printf("arg1: %s\n", arguments.arg1);
    } 

    if (arguments.arg2) {
        printf("arg2 set\n");
    }

    return 0;
}
