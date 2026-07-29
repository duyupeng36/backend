/* float_literals.c — 浮点字面量的精度陷阱和十六进制浮点 */
#include <stdio.h>

int main(void) {
    // 验证笔记中的精度问题：0.2 不能精确存储
    printf("0.2 = %.20f\n", 0.2);
    // 输出类似: 0.20000000000000001110（不是精确的 0.2）

    // 验证陷阱：0.2 == 0.2000000000000000111 居然为 true
    if (0.2 == 0.2000000000000000111)
        puts("0.2 == 0.2000000000000000111: true（精度陷阱）");

    // 十六进制浮点：精确定点，和二进制一一对应
    double d = 0x1.999999999999aP-3;
    printf("0x1.99...P-3 = %.20f\n", d);

    // 笔记中的表：同一值 0.2，不同类型精度不同
    float  f = 0.2f;       // 32 位
    double df = 0.2;        // 64 位
    long double ld = 0.2L;  // 80/128 位
    printf("float:       %a\n", f);    // %a 打印十六进制位模式
    printf("double:      %a\n", df);
    printf("long double: %La\n", ld);

    // 不同精度的 0.2 是否相等？
    printf("0.2f == 0.2 : %d\n", f == df);  // float 转 double 后可能不相等
}
