/* narrow_promote.c — 窄类型提升演示 */
#include <stdio.h>

int main(void) {
    unsigned char a = 200;
    unsigned char b = 100;
    printf("a + b = %d (int 提升)\n", a + b);     // 300

    unsigned char c = a + b;
    printf("存回 char: %d (回绕)\n", c);          // 44

    printf("sizeof(a+b) = %zu (已是 int)\n", sizeof(a + b));
    printf("sizeof(a)   = %zu (仍是 char)\n", sizeof(a));

    bool x = 1, y = 1;
    printf("true + true = %d\n", x + y);           // 2
}
