#include "ch1.h"

const static unsigned char *hex_string = "\x49\x27\x6d\x20\x6b\x69\x6c\x6c\x69\x6e\x67\x20\x79\x6f\x75\x72\x20\x62\x72\x61\x69\x6e\x20\x6c\x69\x6b\x65\x20\x61\x20\x70\x6f\x69\x73\x6f\x6e\x6f\x75\x73\x20\x6d\x75\x73\x68\x72\x6f\x6f\x6d";

int main()
{
    base_64_t base64 = base64_encode(hex_string, strlen(hex_string));

    for (int i=0; i<base64.len; i++){
        printf("%c", base64_dic[base64.num[i]]);
	}
    printf("\n");
    
    free(base64.num);
    return 0;
}
