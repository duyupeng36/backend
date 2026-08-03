/* three_max.c — 嵌套 if：从三个数中找出最大值 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc + 1]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <i> <j> <k>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int i = atoi(argv[1]);
    int j = atoi(argv[2]);
    int k = atoi(argv[3]);
    int max;

    if (i > j) {
        if (i > k) max = i;
        else max = k;
    } else {
        if (j > k) max = j;
        else max = k;
    }

    printf("max(%d, %d, %d) = %d\n", i, j, k, max);
    return EXIT_SUCCESS;
}
