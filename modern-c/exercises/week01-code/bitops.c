/* bitops.c - 位运算符练习 */
#include <stddef.h>
#include <stdio.h>
int main(void) {

    size_t number = 0;
    printf("请输入一个正整数: ");
    scanf("%zu", &number);

    bool is_power2 = !(number & (number - 1));
    // printf("二进制: %zbu\n", number);
    printf("二进制: ");
    for (size_t i = 8 * sizeof(size_t) - 1; ; --i) {
        printf("%zu", (number >> i) & 0x1);
        if (i == 0) {
            puts("");
            break;
        }

    }

    size_t count = 0;
    printf("1 的个数:");
    while (number != 0) {
        number & 0x1 ? (++count, number >>= 1) : (number >>= 1);
    }
    printf("%zu\n", count);

    if (is_power2) {
        printf("是 2 的幂\n");
    } else {
        printf("不是 2 的幂\n");
    }


}
