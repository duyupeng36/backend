/* sign_count.c - 统计数组中的正数 负数 和 0 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc + 1]) {

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <num> <num> ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    long numbers[argc - 1];
    
    for (int i = 1; i < argc; ++i) {
        numbers[i - 1] = strtol(argv[i], nullptr, 0);
    }

    int count[3] = {0}; // count[0]: < 0; count[1]: > 0; count[2]: == 0
    for (int i = 0; i < argc - 1; ++i) {
        
        ++count[(numbers[i] > 0) - (numbers[i] < 0) + 1];
    }
    printf("pos=%d, neg=%d, zero=%d\n", count[2], count[0], count[1]);

    return EXIT_SUCCESS;
}
