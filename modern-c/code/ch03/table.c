/* table.c - 输出 1 ~ 10 的平方 和 立方 */
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <n>\n", argv[0]);
        return EXIT_FAILURE;
    }

    long n = strtol(argv[1], nullptr, 0);

    for (long i = 1, square = 1, odd = 1; i <= n; ++i, odd += 2, square += odd) {
        printf("%5ld | %5ld\n", i, square);
    }
    return EXIT_SUCCESS;
}
