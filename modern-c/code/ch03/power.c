/* power.c - 快速幂计算 a ^n */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc + 1]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <base> <exp>\n", argv[0]);
        return EXIT_FAILURE;
    }
    double base = strtod(argv[1], nullptr);
    long exp = strtol(argv[2], nullptr, 0);

    printf("power(%g, %ld)", base, exp);

    if (exp < 0) {
        base = 1 / base;
        exp = -exp;
    }

    double results = 1.0;

    while (exp > 0) {
        if (exp & 0x1) {
            results *= base;
        }
        base *= base;
        exp >>= 1;
    }

    printf("= %g\n", results);

    return EXIT_SUCCESS;
}
