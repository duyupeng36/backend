/* square.c — for 循环基本用法：打印平方表 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return EXIT_FAILURE;
    }
    unsigned long number = strtoul(argv[1], nullptr, 0);

    for (size_t i = 1; i <= number; ++i) {
        printf("%10zu%10zu\n", i, i * i);
    }

    return EXIT_SUCCESS;
}
