/* max3.c - 找出三个输入中的最大值 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc + 1]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <number1> <number2> <number3>", argv[0]);
        return EXIT_FAILURE;
    }
    long number1 = strtol(argv[1], nullptr, 0);
    long number2 = strtol(argv[2], nullptr, 0);
    long number3 = strtol(argv[3], nullptr, 0);

    long max = 0;
    if (number1 > number2) {
        if (number1 > number3) {
            max = number1;
        } else {
            max = number3;
        }
    } else {
        if (number2 > number3) {
            max =number2;
        } else {
            max = number3;
        }
    }

    printf("The largest value is %ld\n", max);

    return EXIT_SUCCESS;
}
