/* numdigits.c - 数字位数统计 */

#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int number = 0;
    printf("请输入一个正整数(>0): ");
    scanf("%d", &number);

    if (number <= 0) {
        fprintf(stderr, "请输入正整数\n");
        return EXIT_FAILURE;
    }

    size_t count = 0;
    size_t sum = 0;
    while (number > 0) {
        ++count;
        sum += number % 10;
        number /= 10;
    }
    printf("位数: %zu\n各位数字之和：%zu\n", count, sum);

    return EXIT_SUCCESS;
}
