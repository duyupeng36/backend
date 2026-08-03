/* dangling_else.c — 悬空 else 演示 */
#include <stdio.h>
#include <stdlib.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdangling-else"

int main(int argc, char* argv[argc + 1]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <x> <y>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    int result = 0;

    // ⚠ 故意的错误写法：else 的缩进暗示匹配外层 if，实际匹配内层 if
    if (y != 0)
        if (x != 0)
            result = x / y;
    else
        printf("Error: y is equal to 0\n");

    // ✅ 正确写法：始终使用 {...}
    if (y != 0) {
        if (x != 0) {
            result = x / y;
        }
    } else {
        printf("Error: y is equal to 0\n");
    }

    printf("result = %d\n", result);
    return EXIT_SUCCESS;
}

#pragma GCC diagnostic pop
