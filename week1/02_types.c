// week1/02_types.c —— C 的基本类型系统
#include <stdio.h>
#include <limits.h>   // 整数范围常量
#include <float.h>    // 浮点范围常量

int main(void) {
    // ===== 整数类型 =====
    // ===== 整数类型 =====
    char c = 'A';            // 1 字节, -128~127 或 0~255
    short s = 32767;         // 2 字节
    int i = 2147483647;      // 4 字节（通常）
    long l = 9223372036854775807L; // 8 字节（64位系统）
    long long ll = 9223372036854775807LL;
    // signed vs unsigned —— C 特有，Python 没有
    unsigned int ui = 4294967295U;  // 无符号，全是正数

    // 打印每个变量的值（消除 unused-variable 警告）
    printf("Values: c=%c s=%d i=%d l=%ld ll=%lld ui=%u\n",
           c, s, i, l, ll, ui);

    // ===== 浮点类型 =====
    float f = 3.1415926535f;       // 4 字节，约 7 位精度
    double d = 3.141592653589793;  // 8 字节，约 15 位精度

    // ===== sizeof —— 看每种类型占多少字节 =====
    printf("=== 各类型大小 (字节) ===\n");
    printf("char:      %2zu  范围: %d ~ %d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("short:     %2zu  范围: %d ~ %d\n", sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("int:       %2zu  范围: %d ~ %d\n", sizeof(int), INT_MIN, INT_MAX);
    printf("long:      %2zu\n", sizeof(long));
    printf("long long: %2zu\n", sizeof(long long));
    printf("float:     %2zu  精度约 7 位\n", sizeof(float));
    printf("double:    %2zu  精度约 15 位\n", sizeof(double));
    printf("void*:     %2zu  (指针大小)\n", sizeof(void*));

    printf("\n=== 对比: Python vs C ===\n");
    printf("Python: a = 42; a = 'hello'   # 同一个变量可以换类型\n");
    printf("C:      int a = 42;            # 类型写死在声明里，不能变\n");

    printf("\n=== 精度损失演示 ===\n");
    printf("float  π = %.15f  (后面是垃圾)\n", f);
    printf("double π = %.15f  (更精确)\n", d);

    return 0;
}
