/* bitwise_ops.c — 位运算符演示 */
#include <stdio.h>

int main(void) {
    unsigned A = 240;   // 0b11110000
    unsigned B = 287;   // 0b000100011111

    printf("A     = %3u (0x%02X)\n", A, A);
    printf("B     = %3u (0x%02X)\n", B, B);
    printf("A | B = %3u (0x%02X)  并集\n", A | B, A | B);
    printf("A & B = %3u (0x%02X)  交集\n", A & B, A & B);
    printf("A ^ B = %3u (0x%02X)  对称差\n", A ^ B, A ^ B);
    printf("~A    = %3u (0x%02X)  补集\n", ~A, ~A & 0xFFFF);

    // 标志位用法
    unsigned flags = 0;
    flags |= 4U;                       // 设置 bit 2
    printf("\nflags = %u\n", flags);
    printf("bit 2 设置? %d\n", (flags & 4U) != 0);
    flags &= ~4U;                      // 清除 bit 2
    printf("bit 2 清除后: %u\n", flags);
}
