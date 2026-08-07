/* swap.c - 演示传值语义：交换两个变量的值 */

#include <stdio.h>
#include <stdlib.h>


void swap(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void swap_pointer(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void) {
    int a = 10;
    int b = 20;

    printf("交换前: a = %d b = %d\n", a, b);
    swap(a, b);
    printf("swap(%d, %d)后: a = %d b = %d(预期失败)\n", a, b, a, b);

    swap_pointer(&a, &b);
    printf("swap_pointer(%p, %p)后: a = %d b = %d\n", &a, &b, a, b);

    return EXIT_SUCCESS;
}
