/* fibonacci.c - 输出 fibonacci 数列的前 n 项 */

#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int n = 0;
    printf("输出一个正整数: ");
    scanf("%d", &n);
    if (n < 0) {
        fprintf(stderr, "请输入正整数\n");
        return EXIT_FAILURE;
    }
    
    int pre = 0;
    int next = 1;
    for (int i = 1; i <= n; ++i) {
        printf("%d ", next);
        
        pre += next;
        next = pre - next;
        pre = pre - next;

        next = pre + next;

        if (!(i % 5)) {
            puts("");
        }
    }
    puts("");

    return EXIT_SUCCESS;
}
