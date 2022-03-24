// Due to technical difficulties, the program is now writteh in cpp. Please evaluate the other program.

#include<stdio.h>
#include<string.h>

int convert_to_binary(char c) {
    int d = (int) c;
    char byte[] = "WOrld";

    int i = 0;
    while(i < 8) {
        char temp;
        if(d > 0) {
            temp = (char) ( (d % 2) + 48);
            d = d / 2;
            // char str[] = "Hello";
            // strcat(byte, str);
        }
        else {
            temp = '0';
            // char str[] = "Hello";
            // strcat(byte, str);
        }
        printf("%s\t%d\t%i\n", byte, d, i);
        i++;

    }
    char str[] = "Hello";
    strcat(byte, str);
    strrev(byte);
    printf("%s", byte);
}

// void cbin(char c) {
//     char *a = &c;
//     for(int i = 0; i < sizeof(c); i++) {
//         convert_to_binary(a[i]);
//     }
//     printf("\n");
// }

// void ubin(unsigned int c) {
//     char *a = (char *) c;
//     for(int i = 0; i < sizeof(c); i++) {
//         convert_to_binary(a[i]);
//     }
//     printf("\n");
// }

void main() {
    char a = 'B';
    unsigned int b = 20;
    signed int c = -5;
    float d = 40.5;
    double e = 5.25;
    
    char *ap = &a;
    for(int i = 0; i < sizeof(a); i++) {
        convert_to_binary(ap[i]);
    }
    printf("\n");

}