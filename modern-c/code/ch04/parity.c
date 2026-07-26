/* parity.c - 片段一个数是奇数还是偶数 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return EXIT_FAILURE;
    }
    long number = strtol(argv[1], nullptr, 0);
    printf("%ld is %s\n", number, !(number % 2) ? "Even number": "Odd number");
    return EXIT_SUCCESS;
}
