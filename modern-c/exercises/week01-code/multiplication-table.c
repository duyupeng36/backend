/* multiplication-table.c - 打印乘法表 */
#include <stdio.h>
int main(void) {
    for (int i = 1; i < 10; ++i) {
        for (int j = 1; j <= i; ++j) {
            printf("%d * %d = %-*d", j, i, j < 2 ? 4 : 5, i * j);
        }
        puts("");
    }
}
