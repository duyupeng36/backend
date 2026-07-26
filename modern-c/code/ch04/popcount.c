#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return EXIT_FAILURE;
    }
    long number = strtol(argv[1], nullptr, 0);

    printf("%ld(%#lx)的二进制表示包含 ", number, number);

    int count[2] = {0, 0}; // count[0]: 0 的个数 count[1]: 1 的个数
    
    while (number > 0) {
        ++count[number & 0x1];
        number >>= 1;
    }
    
    printf("%d 个 1.\n", count[1]);
    
    return EXIT_SUCCESS;;

}
