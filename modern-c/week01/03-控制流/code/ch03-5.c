/* heron2.c — while 语句：使用 Heron 近似计算 1 / x 的值 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 下限和上限迭代限制以 1.0 左右为中心
static double const eps1m01 = 1.0 - 0x1P-03;  // 1.0 - 1 * 2^{-1} = 1 - 0.5
static double const eps1p01 = 1.0 + 0x1P-01;  // 1.0 + 1 * 2^{-1} = 1 + 0.5
static double const eps1m24 = 1.0 - 0x1P-24;  // 1.0 - 1 * 2^{-24}
static double const eps1p24 = 1.0 + 0x1P-24;  // 1.0 + 1 * 2^{-24}

int main(int argc, char* argv[argc + 1]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <a> <max-iter>\n", argv[0]);
        return EXIT_FAILURE;
    }
    double a = strtod(argv[1], nullptr);
    if (a == 0.0) {
        fprintf(stderr, "x can not be zero.\n");
        return EXIT_FAILURE;
    }
    unsigned long max_iter = strtoul(argv[2], nullptr, 0);

    // 猜测初始值: 找到一个 0.5 ~ 1.5 之间的初始值
    double yn = 1.0;
    while (true) {
        double prod = yn * a;
        if (prod < eps1m01) {
            yn *= 2.0;
        } else if (eps1p01 < prod) {
            yn *= 0.5;
        } else {
            break;
        }
    }
    printf("eps1m01 = %.12f\n", eps1m01);
    // Heron 近似求解
    for (size_t i = 0; i < max_iter; ++i) {
        double prod = yn * a;
        // 检查当前迭代目标值是否满足精度要求
        if (prod < eps1m24 || eps1p24 < prod) {
            yn *= 2.0 - prod;
            printf("第 %zu 次迭代: a=%.5e,\tyn=%.5e\ta*yn=%.12f\n", i + 1, a, yn, prod);
        } else {
            break;
        }
    }
    printf("heron: a=%.5e,\tyn=%.5e\ta * yn = %.12f\n", a, yn, a * yn);
    return EXIT_SUCCESS;
}
