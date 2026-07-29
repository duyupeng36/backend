/* implicit_convert.c — 隐式转换的陷阱和规则 */
#include <stdio.h>
#include <limits.h>

int main(void) {
    // 规则一：整数提升
    char a = 1, b = 2;
    printf("sizeof(a+b) = %zu (提升为 int)\n\n", sizeof(a + b));

    // 规则二：整数→浮点
    printf("1 + 0.0  : sizeof=%zu (double)\n", sizeof(1 + 0.0));
    printf("INT_MAX + 0.0F 可能丢失精度\n\n");

    // 规则三：同 Rank 有符号→无符号
    printf("sizeof(1U + 1)  = %zu (unsigned)\n", sizeof(1U + 1));
    printf("sizeof(1L + 1LL) = %zu (long long, 向高 Rank 转)\n\n", sizeof(1L + 1LL));

    // 教材的核心演示：混合符号性的危险
    printf("=== 混合 signed/unsigned 比较 ===\n");
    printf("-1 < 0   : %d (预期 true)\n", -1 < 0);
    printf("-1 < 0U  : %d (预期 true，实际 false! -1 被转成 UINT_MAX)\n", -1 < 0U);

    // 窄化转换陷阱
    unsigned u = 0x80000000;
    unsigned short g = u;   // 截断，只保留低 16 位
    printf("\n0x80000000 → unsigned short: %u (变成了 0)\n", g);

    // 一元 - 的类型
    printf("\n=== 一元 - 的类型 ===\n");
    printf("sizeof(-1)  = %zu (signed int)\n", sizeof(-1));
    printf("sizeof(-1U) = %zu (unsigned, 值是 UINT_MAX)\n", sizeof(-1U));
}
