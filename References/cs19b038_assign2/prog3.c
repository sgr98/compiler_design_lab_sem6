#include <stdio.h>

int main() {
    int number = 9;
    
    for (int i = 0; i < 7; i++) {
        number += i;
    }

    printf("The if statement is easy. %d", number);
    return 0;
}