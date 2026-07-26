/* digitsum.c - 计算整数各位数值之和 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return EXIT_FAILURE;
    }

    long number = strtol(argv[1], nullptr, 0);

    if (number < 0) {
        number = -number;
    }

    long result = 0;
    while (number > 0) {
        result += number % 10;
        if (number / 10) {
            printf("%ld + ", number % 10);
        } else {
            printf("%ld ", number % 10);
        }
        number /= 10;
    }

    printf("= %ld\n", result);

    return EXIT_SUCCESS;
}
