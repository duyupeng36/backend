/* sum.c - 计算一系列整数的和 */

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[argc + 1]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <1> <2> <3> ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    long result = 0;

    for (int i = 1; i < argc; ++i) {
        result += strtol(argv[i], nullptr, 0);
    }
    printf("sum result is %ld\n", result);

    return EXIT_SUCCESS;
}
