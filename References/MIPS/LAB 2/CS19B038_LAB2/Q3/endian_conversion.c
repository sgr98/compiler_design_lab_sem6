#include <stdio.h>

void endian_convert(char *d, int bytes) {
    for(int i = 0; i < bytes / 2; i++) {
        char temp = d[i];
        d[i] = d[bytes - i - 1];
        d[bytes - i - 1] = temp;
    }
}

void endian_print(char *d, int bytes) {
    for(int i = 0; i < bytes; i++) {
        printf("%d => %x at %p\n", i, d[i], (d + i));
    }
    printf("New Value => ");
    for(int i = 0; i < bytes; i++) {
        printf("%x",d[i]);
    }
    printf("\n");

    printf("Converted Architecture is ");
    if(d[0] == 0x12)
        printf("Big Endian\n\n");
    else
        printf("Little Endian\n\n");
}

void main() {
    int sample = 0x12345678;
    char *d = (char *) &sample;

    printf("This architecture is ");
    if(d[0] == 0x12)
        printf("Big Endian\n\n");
    else
        printf("Little Endian\n\n");

    endian_convert(d, sizeof(sample));
    endian_print(d, sizeof(sample));

    endian_convert(d, sizeof(sample));
    endian_print(d, sizeof(sample));
}