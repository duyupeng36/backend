/* signed_repr.c — 有符号补码表示和 INT_MIN 不对称 */
#include <stdio.h>
#include <limits.h>

int main(void) {
    // 正值在有无符号下位模式相同
    unsigned u = 240;
    signed   s = 240;
    printf("u=240: %u, s=240: %d (同一块内存解释不同)\n", u, s);

    // 补码：-A = ~A + 1
    printf("~240 + 1 = %u (= -240 的无符号表示)\n", ~240u + 1);

    // INT_MIN 的不对称性
    printf("\nINT_MAX  = %d\n", INT_MAX);
    printf("INT_MIN  = %d\n", INT_MIN);
    printf("INT_MIN < -INT_MAX: %d\n", INT_MIN < -INT_MAX);
    // -INT_MIN 是 UB，不要写！
}
