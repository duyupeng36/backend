/* temperature-conversion.c - 温度转换程序 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    double temperature = 0;
    int type = 0;
    printf("请输入温度值和单位（如 36.5 C）：");
    scanf("%lf", &temperature);
    while ((type = getchar()) != EOF && isblank(type));

    switch (type) {
        case 'f':
        case 'F':
            printf("转换结果: %g C\n", (temperature - 32) * 5 / 9);
            break;
        case 'c':
        case 'C':
            printf("转换结果: %g F\n", temperature * 9 / 5 + 32);
            break; 
        default:
            printf("不支持该温度类型\n");
    }

    return EXIT_SUCCESS;
}
