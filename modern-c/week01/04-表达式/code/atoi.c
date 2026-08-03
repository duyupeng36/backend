/* atoi.c — 将字符串转换为 int 类型的整数 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number>", argv[0]);
        return EXIT_FAILURE;
    }
    
    char const*const number = argv[1];

    size_t start = 0;
    // 跳过空白字符
    for (; isspace(number[start]); ++start); // for 的依赖块是空语句
    
    // 处理正负号
    int sign = number[start] == '-' ? -1 : 1;
    
    // 跳过正负号
    if (number[start] == '-' || number[start] == '+') {
        ++start;
    }

    int n = 0;
    for (n = 0; isdigit(number[start]); ++start) {
        n = 10 * n + (number[start] - '0');
    }
    n *= sign; // 最终答案

    printf("%s convert to %d(sizeof %d = %zu)\n", number, n, n, sizeof(n));

    return EXIT_SUCCESS;
}

