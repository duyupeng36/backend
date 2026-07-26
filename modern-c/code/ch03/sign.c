/* sign.c - 判断一个整数的符号 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return EXIT_FAILURE;
    }

    long number = strtol(argv[1], nullptr, 0);
    
    if (number > 0) {
        printf("Positive number.\n");
    } else if (number < 0) {
        printf("Negative number.\n");
    } else {
        printf("zero.\n");
    }

    return 0;
}
