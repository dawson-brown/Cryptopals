#include "ch6.h"

static char *text1 = "this is a test";
static char *text2 = "wokka wokka!!!";

int main()
{

    int distance = hamming_distance(text1, text2);

    printf("Hamming distance: %d\n", distance);

    return 1;
}