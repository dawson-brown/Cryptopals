#include "ch2.h"

const static unsigned char *hex1_string = "\x1c\x01\x11\x00\x1f\x01\x01\x00\x06\x1a\x02\x4b\x53\x53\x50\x09\x18\x1c";
const static unsigned char *hex2_string = "\x68\x69\x74\x20\x74\x68\x65\x20\x62\x75\x6c\x6c\x27\x73\x20\x65\x79\x65";
const static int len = 19;

int main()
{
    unsigned char *xorSum = xor_sum(hex1_string, hex2_string, len);
    print_hex(xorSum, len);
}