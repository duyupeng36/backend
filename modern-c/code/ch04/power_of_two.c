/* power_of_two.c */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc + 1]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    long number = strtol(argv[1], NULL, 0);
    if (number <= 0) {
        fprintf(stderr, "<number> must be positive numbers\n");
        return EXIT_FAILURE;
    }
    printf("%ld is %s\n", number, !(number & (number - 1)) ? "power of two" : "not power of two");
    return EXIT_SUCCESS;
}
