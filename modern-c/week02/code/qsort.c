/* qsort.c - 快速排序算法示例 */

#include <stddef.h>
#include <stdio.h>

constexpr size_t size = 10;

void quick_sort(int array[], size_t size);

int main(void) {

    int array[size] = {};

    for (size_t i = 0; i < size; ++i) {
        scanf("%d", &array[i]);
    }

    quick_sort(array, size);

    for (size_t i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return  0;
}


static int split(int array[], int low, int height) {
    // 挑选一个主元：采用简单的方法，直接选 low 
    int pivot = array[low];
    
    for (;;) {
        // 1. 将 pivot 右侧小于 pivot 的元素移动到左侧
        while (low < height && pivot <= array[height]) --height;
        if (low >= height) break;
        array[low++] = array[height];
        // 2. 将  pivot 左侧大于 pivot 的元素移动到右侧
        while (low < height && array[low] <= pivot) ++low;
        if (low >= height) break;
        array[height--] = array[low];
    }
    array[height] = pivot;
    return height;
}

static void qsort(int array[], int low, int height) {
    if (low >= height) return;

    int mid = split(array, low, height);
    qsort(array, low, mid - 1);
    qsort(array, mid + 1, height);
}

void quick_sort(int array[], size_t size) {
    qsort(array, 0, size - 1);
}


