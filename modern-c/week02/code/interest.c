/* interest.c - 计算投资利息（单利） */

#include <stdio.h>
#include <stdlib.h>

#define SIZE(array) (sizeof(array) / sizeof((array)[0]))
#define INITIAL_BALANCE 100.0

int main(void) {

    double value[5] = {};

    double rate = 0.0; // 利率
    int year = 0; // 投资年数

    printf("请输入利率（%%）: ");
    scanf("%lf", &rate);
    printf("请输入投资年数: ");
    scanf("%d", &year);

    printf("\nYears");
    for (size_t i = 0; i < SIZE(value); ++i) {
        printf("%6.0f%%", rate + i);
        value[i] = INITIAL_BALANCE;
    }
    puts("");

    for (int y = 1; y <= year; ++y) {
        printf("%3d  ", y);
        for (size_t i = 0; i < SIZE(value); ++i) {
            value[i] += (rate + 1) / 100.0 * value[i];
            printf("%7.2f", value[i]);
        }
        puts("");
    }

    return EXIT_SUCCESS;

}

