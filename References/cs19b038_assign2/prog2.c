#include <stdio.h>

int main() {
    int number = 9;
    int t = 10;
    
    if (number > 0) {
        number = number + t;
        t = t + 1;
    }

    printf("The if statement is easy.");
    return 0;
}