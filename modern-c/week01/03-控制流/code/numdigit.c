#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc + 1]) {
    if (argc != 2)  {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return EXIT_FAILURE;
    }

    long number = strtol(argv[1], nullptr, 0);
    printf("%ld has ", number);
    if (number < 0) {
        number = -number;
    }

    size_t count = 0;

    do {
        number /= 10;
        ++count;
    }while (number != 0);

    printf("%zu digit(s)\n", count);

    return EXIT_SUCCESS;
}
