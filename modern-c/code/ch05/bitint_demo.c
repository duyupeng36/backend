/* bitint_demo.c — _BitInt 精确宽度演示 */
#include <stdio.h>
#include <limits.h>

int main(void) {
    // 3 位无符号：0..7，溢出回绕
    unsigned _BitInt(3) u3 = 7wbu;
    printf("u3 = %d, u3 + 1 = %d (回绕!)\n", u3, u3 + 1wbu);

    // 3 位有符号：-4..3
    signed _BitInt(3) s3 = 3wb;
    printf("s3 = %d, s3 + 1 = %d\n", s3, s3 + 1wb);

    // constexpr 精确位掩码
    constexpr unsigned _BitInt(4) mask = -1;   // 0b1111
    printf("mask = 0x%X\n", mask);

    printf("BITINT_MAXWIDTH = %d\n", BITINT_MAXWIDTH);
}
