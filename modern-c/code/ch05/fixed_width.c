/* fixed_width.c — 定宽整数类型和 wN 格式 */
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void) {
    uint32_t n = 78;
    int64_t big = INT64_MAX;

    // C23 wN 格式说明符
    printf("n is %w32u, big is %w64d\n", n, big);

    // 传统方式（C23 之前）
    printf("n is %" PRIu32 ", big is %" PRId64 "\n", n, big);
}
