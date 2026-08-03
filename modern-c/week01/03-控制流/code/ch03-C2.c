/* 挑战任务：实现数值导数：已知 F(x) 求 f(x)，用 sin 验证 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[argc + 1]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <x>\n", argv[0]);
        return EXIT_FAILURE;
    }
    double x = strtod(argv[1], nullptr);

    for (double h = 0.1; ; h /= 10.0 ) {
        double sin_prime = (sin(x + h) - sin(x - h)) / (2 * h);
        printf("sin(%.5e)' = %.12f :  cos(%.5e) = %.12f\n", x,  sin_prime, x, cos(x));
        if (sin_prime - cos(x) < 1e-10) {
            break;
        }
    }
    return EXIT_SUCCESS;

}


