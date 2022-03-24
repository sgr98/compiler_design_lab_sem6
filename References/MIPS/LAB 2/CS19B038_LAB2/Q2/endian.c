#include <stdio.h>

void main() {
    int sample = 0x12345678;
    char *d = (char *) &sample;
    for(int i = 0; i < 4; i++) {
        printf("%d => %x at %p\n", i, d[i], (d + i));
    }

    if(d[0] == 0x12) {
        printf("Big Endian");
    }
    else {
        printf("Little Endian");
    }
}