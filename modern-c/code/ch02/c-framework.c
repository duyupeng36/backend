/* 第一部分：头文件包含 */
#include <stdio.h>

/* 第二部分：宏定义 */
#define SIZE 5

/* 第三部分：函数声明 */
void swap(void* a, void* b);

/* 第四部分：main 函数定义 */
int main(void) {
    int a = 10;
    int b = 20;
    printf("before swap: a = %d,b=%d\n", a, b);
    swap(&a, &b);
    printf("after swap: a = %d,b=%d\n", a, b);
    return 0;
}

/*第五部分：函数定义*/
void swap(void* a, void* b) {
    int temp = *(int*)a;
    *(int*)a = *(int*)b;
    *(int*)b = temp;
}
