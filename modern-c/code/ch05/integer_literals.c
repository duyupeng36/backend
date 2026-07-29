/* integer_literals.c — 验证笔记中四条规则和陷阱 */
#include <stdio.h>

int main(void) {
    // 同一个值 42 的四种进制（验证笔记的表）
    printf("42      = %d (十进制)\n", 42);
    printf("052     = %d (八进制)\n", 052);
    printf("0x2A    = %d (十六进制)\n", 0x2A);
    printf("0b101010 = %d (二进制, C23)\n\n", 0b101010);

    // 规则一：字面量永远非负
    // -34 是对 34 取负，不是"负字面量"
    printf("sizeof(-34) = %zu (signed int)\n\n", sizeof(-34));

    // 规则二：十进制有符号 -> 规则三：第一个能放下的有符号类型
    printf("sizeof(42)      = %zu (int)\n", sizeof(42));
    printf("sizeof(2147483648) = %zu (long, 超出 int)\n",
           sizeof(2147483648));
    printf("\n");

    // 规则四：非十进制可无符号
    // 演示陷阱：0xFFFF'FFFF
    unsigned u = 0xFFFF'FFFF;
    printf("0xFFFF'FFFF as unsigned = %u\n", u);
    // 赋值给 int：窄化转换，行为由实现定义
    int x = 0xFFFF'FFFF;
    printf("0xFFFF'FFFF as int     = %d (窄化，值不确定)\n\n", x);

    // 后缀表验证
    printf("sizeof(1U)   = %zu (unsigned)\n", sizeof(1U));
    printf("sizeof(1L)   = %zu (long)\n", sizeof(1L));
    printf("sizeof(1LL)  = %zu (long long)\n", sizeof(1LL));
    printf("sizeof(1UL)  = %zu (unsigned long)\n", sizeof(1UL));
    printf("sizeof(1ULL) = %zu (unsigned long long)\n", sizeof(1ULL));
}
