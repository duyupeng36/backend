/* leap.c - 判断年份是否是闰年 */
#include <stdio.h>
#include <stdlib.h>
int main(void) {

    int year = 0;
    printf("请输入年份: ");
    scanf("%d", &year);

    if (!(year % 400) || (!(year % 4) && (year % 100))) {
        printf("%d 是润年\n", year);
    } else {
        printf("%d 不是闰年\n", year);
    }

    return EXIT_SUCCESS;
}
