/* factorial.c - 阶乘 n! */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return EXIT_FAILURE;
    }
    size_t number = (size_t)strtoull(argv[1], NULL, 0);
    
    size_t result = 1;
    size_t pre_result = 0;

    for (size_t i = number; i >= 1; --i) {
        pre_result = result;
        result *= i;

        if (result < pre_result) {
            fprintf(stderr, "Overflowe of multiplay size_t value\n");
            return EXIT_FAILURE;
        }
    }

    printf("%zu! = %zu\n", number, result);
    return EXIT_SUCCESS;
}
