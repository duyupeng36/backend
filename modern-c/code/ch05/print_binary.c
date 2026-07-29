
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[argc + 1]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned number = (unsigned)strtol(argv[1], nullptr, 0);
    for(size_t i = UINT_WIDTH; i > 0; --i) {
        printf("%d", (number >> (i - 1)) & 0x1);
    }
    printf("\n");
    return EXIT_SUCCESS;
}

