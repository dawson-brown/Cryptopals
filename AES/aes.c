#include <stdlib.h>
#include <stdio.h>

int main(){
    int i = 95647587534638367;
    unsigned char *p = (unsigned char *)&i;

    for(int j=0; j<sizeof(i); j++){
        printf("%x,", *p++);
    }
    printf("\n");
}