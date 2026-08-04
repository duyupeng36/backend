/* reverse.c - 数组反向 */
#include <stdio.h>
#include <stdlib.h>

constexpr size_t size = 10;

int main(void) {

    int array[size] = {};

    printf("请输入 %zu 个整数: ", size);
    
    for (size_t i = 0; i < size; ++i) {
        scanf("%d", &array[i]);
    }

    for (size_t i = 0; i < size / 2; ++i) {
        array[i] += array[size - i - 1];
        array[size - i - 1] = array[i] - array[size - i - 1];
        array[i] = array[i] - array[size - i - 1];
    }

    printf("反向结果:");
    for (size_t i = 0; i < size; ++i) {
        printf(" %d", array[i]);
    }
    puts("");

    return EXIT_SUCCESS;
}

