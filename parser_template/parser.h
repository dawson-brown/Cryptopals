#include <argp.h>

const char *argp_program_version;

const char *argp_program_bug_address;

/*
   Description of non-option arguments
*/
static char args_doc[] = "";

/*
  Program documentation.
*/
static char doc[] = "";

/*
   the argp structure--for use in main.
*/

extern struct argp_option options[];

enum parser_opts;

error_t parse_opt (int key, char *arg, struct argp_state *state);

static struct argp argp = {options, parse_opt, args_doc, doc};

struct arguments arguments;

struct arguments
{                   
  char *arg1;            /* arguments */
  int arg2;     
};
