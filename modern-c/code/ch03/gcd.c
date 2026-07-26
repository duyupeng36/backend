/* gcd.c - 欧几里得算法 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc + 1]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <number1> <number2>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    long number1 = strtol(argv[1], nullptr, 0);
    long number2 = strtol(argv[2], nullptr, 0);
    
    if (number1 <= 0 || number2 <= 0) {
        fprintf(stderr, "<number1> and <number2> must be greate than zero\n");
        return EXIT_FAILURE;
    }
    // 加上 number1 < number2
    if (number1 > number2) {
        long temp = number1;
        number1 = number2;
        number2 = temp;
    }
    printf("GCD(%ld, %ld) = ", number1, number2);
    while (number1 > 0) {
        int r = number2 % number1;  // r < number1
        number2 = number1;
        number1 = r;
    }
    printf("%ld\n", number2);

    return EXIT_SUCCESS;
}
