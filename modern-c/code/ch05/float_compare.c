/* float_compare.c - 验证三种精度 0.2 是否相等 */

#include <stdio.h>
#include <stdlib.h>


int main(void) {
    float f = 0.2f;
    double df = 0.2;
    long double ld = 0.2L;

    printf(".2f == .2 : %s\n", f == df ? "true": "false");
    printf(".2f == .2l : %s\n", f == ld ? "true": "false");
    printf(".2 == .2l : %s\n", df == ld ? "true": "false");
    
    return EXIT_SUCCESS;
}

