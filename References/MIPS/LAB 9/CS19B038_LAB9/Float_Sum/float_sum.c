#include <stdio.h>
#include <inttypes.h>

double float_sum(double, double);

int main() {
    double a = 9.5;
    double b = 5.92;

    printf("%.4f\n", float_sum(a, b));
    return 0;
}