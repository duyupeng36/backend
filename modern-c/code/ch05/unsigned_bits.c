/* unsigned_bits.c — 无符号整数的位模式和精度 */
#include <stdio.h>
#include <limits.h>

int main(void) {
    // 精度和最大值的关系：2^p - 1
    printf("UINT_WIDTH  = %d, UINT_MAX  = %u  (2^%d - 1)\n",
           UINT_WIDTH, UINT_MAX, UINT_WIDTH);
    printf("ULONG_WIDTH = %d, ULONG_MAX = %lu\n\n",
           ULONG_WIDTH, ULONG_MAX);

    // 展示值 240 的位模式（16 位精度下）
    unsigned short val = 240;
    printf("240 的二进制 (16 位): ");
    for (int i = UINT_WIDTH - 1; i >= 0; --i)  // 从 MSB 到 LSB
        printf("%d", (val >> i) & 1);
    printf("\n");

    // LSB 测试：最低有效位是 0 还是 1？
    printf("240 & 1 = %d (LSB)\n", val & 1);
    // MSB：最高有效位（对 unsigned short，精度 16，MSB 是 bit15）
    printf("240 & 0x8000 = %d (MSB)\n", (val & 0x8000) != 0);
}
