// week1/03_operators_flow.c —— 运算符与控制流：Python vs C
#include <stdio.h>
#include <stdbool.h>  // C99 之后才有 bool 类型

int main(void) {
    // ===== 算术运算符（跟 Python 几乎一样）=====
    int a = 10, b = 3;
    printf("=== 算术 ===\n");
    printf("10 + 3  = %d\n", a + b);
    printf("10 - 3  = %d\n", a - b);
    printf("10 * 3  = %d\n", a * b);
    printf("10 / 3  = %d   ← 注意！整数除法截断，不是 3.333\n", a / b);
    printf("10 %% 3  = %d   ← 取模（Python 也是 %%）\n", a % b);

    // 想要浮点结果？至少一个操作数是浮点
    printf("10.0/3  = %.3f   ← 浮点除法\n", 10.0 / 3);

    // ===== 比较运算符 =====
    printf("\n=== 比较（跟 Python 一样）===\n");
    printf("10 > 3   = %d  (1=true, 0=false)\n", a > b);
    printf("10 == 3  = %d\n", a == b);
    printf("10 != 3  = %d\n", a != b);

    // ===== 逻辑运算符（与 Python 不同！）=====
    printf("\n=== 逻辑（C 用 && || !，不是 and or not）===\n");
    printf("1 && 1 = %d   ← Python: True and True\n", 1 && 1);
    printf("1 || 0 = %d   ← Python: True or False\n", 1 || 0);
    printf("!1     = %d   ← Python: not True\n", !1);

    // ===== 短路求值（跟 Python 一样）=====
    int x = 0;
    if (x != 0 && 10 / x > 5) {  // 10/x 不会执行，因为 x!=0 为假
        printf("不会走到这里\n");
    }
    printf("短路求值保护了除零错误\n");

    // ===== if-else =====
    printf("\n=== 控制流 ===\n");
    int score = 85;
    if (score >= 90) {
        printf("A\n");
    } else if (score >= 80) {
        printf("B\n");           // 会走到这里
    } else {
        printf("C\n");
    }

    // ===== switch =====
    int day = 3;
    switch (day) {
        case 1: printf("Monday\n");  break;
        case 2: printf("Tuesday\n"); break;
        case 3: printf("Wednesday\n"); break;  // 没有 break 会穿透！
        default: printf("Other\n");
    }

    // ===== 循环 =====
    printf("\nfor 循环: ");
    for (int i = 0; i < 5; i++) {   // C99: 可以在 for 里声明变量
        printf("%d ", i);
    }
    printf("\n");

    printf("while 循环: ");
    int count = 3;
    while (count > 0) {
        printf("%d ", count);
        count--;
    }
    printf("\n");

    return 0;
}
