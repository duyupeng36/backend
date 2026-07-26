/* calculator.c - 简易计算器 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // 提供字符检查函数

int main(void) {
    int left_operand = {0};
    int right_operand = {0};
    char operator = {0};

    printf("请输入表达式: ");
    // 读取左操作数
    scanf("%d", &left_operand);
    
    // 读取运算符
    while ((operator = getchar())) {
        if (!isblank(operator)) {
            break;
        }
    }
    
    // 读取右操作数
    scanf("%d", &right_operand);

    switch (operator) {
        case '+':
            printf("%d + %d = %d\n", left_operand, right_operand, left_operand + right_operand);
            break;
        case '-':
            printf("%d - %d = %d\n", left_operand, right_operand, left_operand - right_operand);
            break;
        case '*':
            printf("%d * %d = %d\n", left_operand, right_operand, left_operand * right_operand);
            break;
        case '/':
            if (right_operand) {
                printf("%d / %d = %g\n", left_operand, right_operand, (double)left_operand / right_operand);
            } else {
                fprintf(stderr, "ERROR: 除数不能为 0\n");
                return EXIT_FAILURE;
            }
            break;
        default:
            printf("not support operator %c\n", operator);
    }

    return EXIT_SUCCESS;
}

