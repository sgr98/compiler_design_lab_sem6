#include <stdio.h>
#include <inttypes.h>

int64_t maxoftwo(int64_t, int64_t);     //Just declare the function, function definition is present in assembly code

int main() {
    int64_t a = maxoftwo(2, -6);
    printf("%ld\n", a);
    printf("%ld\n", maxoftwo(2, -6));
    printf("%ld\n", maxoftwo(2, 3));
    printf("%ld\n", maxoftwo(-2, 4));
    printf("%ld\n", maxoftwo(2, 4));
    return 0;
}