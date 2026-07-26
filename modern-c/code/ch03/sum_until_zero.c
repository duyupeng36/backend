/* sum_until_zero.c - while (true) + break: 返回读取用户输入的整数，累加求和 */
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int number = 0;
    int total = 0;
    while (true) {
        printf("请输入一个整数(0表示退出)：");
        scanf("%d", &number);
        if (!number) {
            break;
        }
        total += number;
    }
    printf("total = %d\n", total);
    return EXIT_SUCCESS;
}
