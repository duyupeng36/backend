/* gcd.c - 计算两个数的最大公因数 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int a = 0;
    int b = 0;
    printf("请输入两个正整数: ");
    scanf("%d%d", &a, &b);

    printf("gcd(%d, %d) = ", a, b);
    // 假设 a < b;
    if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    

    while (a < b) {
       int r = b % a;
       if (r == 0) {
           break;
       }
       b = a;
       a = r;
    }
    printf("%d\n", a);

    return EXIT_SUCCESS;
}
