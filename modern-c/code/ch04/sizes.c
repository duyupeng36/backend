/* sizes.c - 使用 sizeof 运算符检查不同类型的尺寸 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    printf("=========== 类型尺寸==========\n");
    printf("size_t: %zu\n", sizeof(size_t));
    printf("int   : %zu\n", sizeof(int));
    printf("double: %zu\n", sizeof(double));
    printf("=========== SIZE_MAX ==========\n");
    printf("SIZE_MAX: %zu\n", SIZE_MAX);
    printf("===============================\n");

    return EXIT_SUCCESS;
}
