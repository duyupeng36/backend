#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
int main(void) {

    uint16_t u16 = 0xef;
    uint32_t u32 = 0xffae;
    int64_t i64 = 0x7fffffffffffffff;

    printf("%w16u - %w32u - %w64d\n", u16, u32, i64);
    return EXIT_SUCCESS;
}
