#include <stdio.h>

int sum(int n) {
    if (n > 0)
        return n + sum(n - 1);
    return 0;
}

int main() {
    int number = 9;
    
    number = sum(number);

    return 0;
}