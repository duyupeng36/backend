/* square2.c — for 循环：两个循环变量 + 迭代优化 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return EXIT_FAILURE;
    }
    unsigned long number = strtoul(argv[1], nullptr, 0);

    for (size_t i = 1, square = 1, odd = 1;
         i <= number;
         ++i, odd += 2, square += odd) {
        printf("%10zu%10zu\n", i, square);
    }

    return EXIT_SUCCESS;
}
