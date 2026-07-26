/* counter.c - 计数器 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc + 1]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <n>\n", argv[0]);
        return EXIT_FAILURE;
    }
    size_t n = strtoull(argv[1], nullptr, 0);
    size_t result = 0;
    
    for (size_t i = 0; i < n; ++i) {
        ++result;
        printf("result = %zu\n", result);
    }


    return EXIT_SUCCESS;
}
