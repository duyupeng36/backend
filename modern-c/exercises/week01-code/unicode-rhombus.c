/* unicode-rhombus.c - 输出 unicode 菱形图像 */
#include <stdio.h>
#include <stdlib.h>
int main(void) {

    size_t layer = 0;
    printf("请输入一个正奇数: ");
    scanf("%zu", &layer);
    if (!(layer & 0x1)) {
        fprintf(stderr, "请输入奇数\n");
        return EXIT_FAILURE;
    }
    
    // 打印上半部分
    for (size_t i = 1; i <= layer / 2; ++i) {
        for (size_t j = 0; j < 2 * i - 1; ++j) {
            j == 0 ? printf("%*c", (int)(layer - i), '*'): printf("*");
        }
        puts("");
    }

    // 打印下半部分
    for(size_t i = layer / 2 + 1; i; --i) {
        for (size_t j = 2 * i - 1; j; --j) {
            j == 2 * i - 1 ? printf("%*c", (int)(layer - i), '*') : printf("*"); 
        }
        puts("");
    }
}
