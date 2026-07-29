#include <stdio.h>

#define STOP 999999999

int main(void) {
    int a = 0;
    volatile int b = 0;

    for (int i = 1; i < STOP; ++i) {
        a += i;
    }
    printf("a = %d\n", a);

    for (int i = 1; i < STOP; ++i) {
        b += i;
    }
    printf("b = %d\n", b);

    return 0;
}

