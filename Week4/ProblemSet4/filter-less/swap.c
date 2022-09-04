#include <stdio.h>

int main (void) {
    int a = 32;
    int b = 34;

    int temp;

    temp = a;
    a = b;
    b = temp;

    printf("%i\n", a);
    printf("%i\n", b);
}