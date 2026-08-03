/* binsearch.c — 从一个有序数组中查找一个元素 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
int main(void) {

    size_t size = 0;
    
    printf("请输入数组大小: ");
    scanf("%zu", &size);

    long numbers[size];

    printf("请数组 %zu 个有序的整数: ", size);
    for (size_t i = 0; i < size; ++i) {
        scanf("%ld", &numbers[i]);
    }

    long target = 0;
    printf("输入需要查找的目标值: ");
    scanf("%ld", &target);

    long left = 0;
    long right = size - 1;
    long index = -1;
    while (left <= right) {
        // 整数除法
        long mid = (left + right) / 2;
        if (target < numbers[mid]) {
            right = mid - 1;
        } else if (target > numbers[mid]) {
            left = mid + 1;
        } else {
            index = mid;
            break;
        }
    }

    if (index == -1) {
        printf("没找到目标值 %ld\n", target);
    } else {
        printf("找到目标值 %ld 的索引为 %ld\n", target, index);
    }

    return  EXIT_SUCCESS;
}

