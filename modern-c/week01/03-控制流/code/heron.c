#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[argc + 1]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <x> <error>\n", argv[0]);
        return EXIT_FAILURE;
    }
    double x = strtod(argv[1], nullptr);
    if (x == 0.0) {
        fprintf(stderr, "x can not be zero.\n");
        return EXIT_FAILURE;
    }
    double error = strtod(argv[2], nullptr);

    // 猜测初始值
    double yn = fabs(x) > 1.0 ? 1 / x : x;

    // 终止条件 g(y) - 0 < error ==> 1/yn - x < error ==> 1 - x * yn < errr
    while (fabs(1 - x * yn) >= error) {
        yn *= (2 - yn * x);
    }

    printf("1 / %.2g = %.2g\n", x, yn);

    return EXIT_SUCCESS;
}
