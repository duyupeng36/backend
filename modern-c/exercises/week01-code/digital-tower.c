/* digital-tower.c - 数字塔 */
#include <stdio.h>
#include <stdlib.h>


size_t digit_count(size_t number) {
    size_t count = 0;
    do {
        ++count;
        number /= 10;
    } while(number != 0);
    return count;
}

int main(void) {

    size_t layer = 0;
    printf("请输入一个正奇数: ");
    scanf("%zu", &layer);
    if (!(layer & 0x1)) {
        fprintf(stderr, "请输入一个奇数!\n");
        return EXIT_FAILURE;
    }

    size_t count = digit_count(layer);

    for (size_t i = 1; i <= layer; ++i) {
        for (size_t j = 0; j < i; ++j) {
            j == 0 ? printf("%*zu", (int)(layer - i + count), i): printf("%*zu", (int)count + 1, i);
        } 
        puts("");
    }

    return EXIT_FAILURE;
}
