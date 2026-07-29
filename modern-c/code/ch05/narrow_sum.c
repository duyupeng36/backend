/* narrow_sum.c - 窄类型累加 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    char sumc = 0;
    int sumi = 0;

    for (int i = 1; i <= 100; ++i) {
        sumc += i;
        sumi += i;
    }
    printf("sumc = %d\tsumi = %d\n", sumc, sumi);
    return EXIT_SUCCESS;
}
