#include <argp.h>
#include <string.h>
#include <stdlib.h>

const char *argp_program_version;

const char *argp_program_bug_address;

/*
   Description of non-option arguments
*/
static char args_doc[] = "The 2 numbers of equal length to XOR";

/*
  Program documentation.
*/
static char doc[] = "";

/*
   the argp structure--for use in main.
*/
extern struct argp_option options[];

error_t parse_opt (int key, char *arg, struct argp_state *state);

static struct argp argp = {options, parse_opt, args_doc, doc};

struct arguments arguments;

struct arguments
{                   
  char *args[2];            /* arguments */     
};

void verify_arguments(struct arguments arguments);
