# 第一周-综合练习答案

> 涵盖：程序基础、控制语句、表达式、基本值和数据、控制流

---

## 一、基础概念题（口头回答）

### Q01【表达式、基本值和数据】

解释以下 C 表达式的类型和值（假设 `int` 为 32 位）

```c
a. -1U
b. 0x8000'0000
c. sizeof(double)
d. 3 / 2
e. 3.0 / 2
```

**答案：**

+ `-1U` 的类型是 `unsigned int` 值是 `-1U = (UINT_MAX + 1) - 1U MOD (UINT_MAX + 1) = UINT_MAX`
+ `0x8000'0000` 的类型是 `unsigned int` 值是 `2^{31}`
+ `sizeof(double)` 的类型是 `size_t` 值是 `8`
+ `3 / 2` 的类型是 `int` 值是 `1`
+ `3.0 / 2` 的类型是 `double` 值是 `1.5`



---

### Q02【表达式】

以下代码的输出是什么？为什么？

```c
int x = 5;
printf("%d %d %d\n", x++, x, ++x);
```

**答案：**

+ 输出: 未知的
+ 原因：在一个表达式中修改了两次对象，是未定义行为

---

### Q03【快速入门】

解释 `const` 和 `constexpr` 的区别。

**答案：**

+ `const` 限定对象是只读的，对象的值在运行时获取
+ `constexpr` 定义的是编译时常量对象。在编译器求值

---

### Q04【控制语句】

以下代码的输出是什么？

```c
int x = 10;
if (x > 5)
    if (x > 15)
        printf("A\n");
else
    printf("B\n");
```

**答案：**

输出是 `B`。`else` 子句与内层的 `if` 匹配。`x` 的值是 `10` 大于 `5` 但是小于 `15` 因此输出 `B`

---

### Q05【控制语句】

`switch` 语句中，如果忘记写 `break`，会发生什么？举例说明。

**答案：** 出现贯穿现象。例如

```c
int test = 3
switch (test) {
    case 1:
        printf("-");
    case 2:
        printf("--");
    case 3:
        printf("---");
    case 4:
        printf("----");
    case 5:
        printf("-----");
    default:
        printf("======");
}
```

输出结果为

```c
---
----
-----
======
```

---

### Q06【控制语句】

`while` 循环和 `do-while` 循环的核心区别是什么？各举一个适用场景。

**答案：**

核心区别：

+ `while` 语句在执行循环体之前求值
+ `do-while` 语句在执行循环体之后求值

比如，想要计算整数的位数，使用 `do-while`，而不是 `while`。因为，当输入数字是 0 时，也需要进行计算

---

## 二、编程题

### P01：温度转换器（10 分钟）【快速入门、控制语句】

编写程序，实现摄氏度与华氏度的互相转换。

**要求**：

- 用户输入温度值和单位（C 或 F）
- 输出转换后的温度
- 保留 1 位小数

**公式**：$F = C \times 9/5 + 32$

**示例输出**：

```
请输入温度值和单位（如 36.5 C）：100 C
转换结果：212.0 F
```

**答案：**

```c
/* temperature-conversion.c - 温度转换程序 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    double temperature = 0;
    int type = 0;
    printf("请输入温度值和单位（如 36.5 C）：");
    scanf("%lf", &temperature);
    while ((type = getchar()) != EOF && isblank(type));

    switch (type) {
        case 'f':
        case 'F':
            printf("转换结果: %g C\n", (temperature - 32) * 5 / 9);
            break;
        case 'c':
        case 'C':
            printf("转换结果: %g F\n", temperature * 9 / 5 + 32);
            break;
        default:
            printf("不支持该温度类型\n");
    }

    return EXIT_SUCCESS;
}
```



---

### P02：打印乘法表（15 分钟）【控制语句】

编写程序，打印 9×9 乘法表。

**要求**：

- 使用嵌套 `for` 循环
- 输出格式对齐

**示例输出**：

```
1×1=1
1×2=2  2×2=4
1×3=3  2×3=6  3×3=9
...
1×9=9  2×9=18 ... 9×9=81
```

**答案：**

```c
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
```

---

### P03：判断闰年（10 分钟）【控制语句】

编写程序，判断输入的年份是否为闰年。

**规则**：

- 能被 4 整除但不能被 100 整除，或者能被 400 整除

**示例输出**：

```
请输入年份：2024
2024 年是闰年
```

**答案：**

```c
/* leap.c - 判断年份是否是闰年 */
#include <stdio.h>
#include <stdlib.h>
int main(void) {

    int year = 0;
    printf("请输入年份: ");
    scanf("%d", &year);

    if (!(year % 400) || (!(year % 4) && (year % 100))) {
        printf("%d 是闰年\n", year);
    } else {
        printf("%d 不是闰年\n", year);
    }

    return EXIT_SUCCESS;
}
```



---

### P04：数字位数统计（15 分钟）【控制语句】

编写程序，统计一个正整数的位数，并输出各位数字之和。

**要求**：

- 使用 `while` 循环
- 不使用字符串

**示例输出**：

```
请输入一个正整数：12345
位数：5
各位数字之和：15
```

**答案：**

```c
/* numdigits.c - 数字位数统计 */

#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int number = 0;
    printf("请输入一个正整数(>0): ");
    scanf("%d", &number);

    if (number <= 0) {
        fprintf(stderr, "请输入正整数\n");
        return EXIT_FAILURE;
    }

    size_t count = 0;
    size_t sum = 0;
    while (number > 0) {
        ++count;
        sum += number % 10;
        number /= 10;
    }
    printf("位数: %zu\n各位数字之和：%zu\n", count, sum);

    return EXIT_SUCCESS;
}
```



---

### P05：素数判断（15 分钟）【控制语句】

编写程序，判断输入的正整数是否为素数。

**要求**：

- 使用 `for` 循环和 `break`
- 优化：只需检查到 $\sqrt{n}$

**示例输出**：

```
请输入一个正整数：17
17 是素数
```

**答案：**

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    size_t number = 0;
    printf("请输入一个正整数：");
    scanf("%zu", &number);

    if (number == 0) {
        fprintf(stderr, "请输入正整数\n");
        return EXIT_FAILURE;
    }

    bool flag = number < 2 ? false : true;
    // 对于每个 number
    for (size_t factor = 3; factor * factor <= number; factor = factor + 2) {
        if (!(number % factor)) {
            flag = false;
            break;
        }
    }
    printf("The number %zu is %s\n", number, flag ? "prime number." : "not prime number.");
    return EXIT_SUCCESS;
}
```

---

### P06：猜数字游戏（20 分钟）【控制语句】

编写一个猜数字游戏。

**要求**：

- 程序随机生成 1~100 的数字（可先用固定值测试）
- 用户反复猜测，程序提示"大了"或"小了"
- 猜对后输出次数

**示例输出**：

```
我想了一个 1~100 的数字，请猜：50
大了！再猜：25
小了！再猜：37
大了！再猜：31
恭喜你，猜对了！共猜了 4 次
```

**答案：**

```c
/* guess-number.c - 猜数字 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
    // 设置随机数种子
    srand(time(NULL));

    // 1 ~ 100 内的随机数
    int target = rand() % 100 + 1;

    int guess = 0;
    size_t count = 0;
    printf("我想了一个 1 ~ 100 的数字，请猜测: ");
    while (true) {
        scanf("%d", &guess);
        ++count;
        if (guess < target) {
            printf("小了！再猜: ");
        } else if (guess > target) {
            printf("大了！再猜: ");
        } else {
            printf("恭喜你，猜对了！共猜了 %zu 次\n", count);
            break;
        }
    }

    return EXIT_SUCCESS;
}
```



---

### P07：位运算练习（15 分钟）【基本值和数据】

编写程序，实现以下功能：

**要求**：

1. 输入一个无符号整数，输出其二进制表示
2. 统计其中 1 的个数
3. 判断是否是 2 的幂

**示例输出**：

```
请输入一个无符号整数：240
二进制：00000000000000000000000011110000
1 的个数：4
不是 2 的幂
```

**提示**：

- 使用移位运算符 `>>` 和位与 `&`
- 判断 2 的幂：`n & (n - 1) == 0`

**答案：**

```c
/* bitops.c - 位运算符练习 */
#include <stddef.h>
#include <stdio.h>
int main(void) {

    size_t number = 0;
    printf("请输入一个正整数: ");
    scanf("%zu", &number);

    bool is_power2 = !(number & (number - 1));
    // printf("二进制: %zbu\n", number);
    printf("二进制: ");
    for (size_t i = 8 * sizeof(size_t) - 1; ; --i) {
        printf("%zu", (number >> i) & 0x1);
        if (i == 0) {
            puts("");
            break;
        }

    }

    size_t count = 0;
    printf("1 的个数:");
    while (number != 0) {
        number & 0x1 ? (++count, number >>= 1) : (number >>= 1);
    }
    printf("%zu\n", count);

    if (is_power2) {
        printf("是 2 的幂\n");
    } else {
        printf("不是 2 的幂\n");
    }
}
```

---

### P08：类型转换陷阱（10 分钟）【基本值和数据】

预测以下程序的输出，然后运行验证：

```c
#include <stdio.h>

int main(void) {
    int a = -1;
    unsigned int b = 0;

    printf("a < 0: %d\n", a < 0);
    printf("b == 0: %d\n", b == 0);
    printf("a < b: %d\n", a < b);

    signed int c = 0x8000'0000;
    printf("c = %d\n", c);

    return 0;
}
```

**问题**：

1. 为什么 `a < b` 的结果不是你预期的？
2. `c` 的值为什么是负数？

**答案：**

输出

```shell
a < 0: 1
b == 0: 1
a < b: 0
c = INT_MIN（-2^{8 * sizeof(int) - 1}）
```

1. `a < b` 混用了符号。有符号类型向无符号类型转换。`-1` 的位模式的无符号表示的值是 `UINT_MAX` 非常大
2. `0x8000'0000` 的值是 $2^{32}$ 大于 `INT_MAX` 类型应该是 `unsigned int`。赋值给 `signed int` 类型时出现溢出。有符号溢出是未定义行为。再我的平台上直接复用了位模式。因此结果才是 `INT_MIN` 

---

### P09：成绩等级判定（10 分钟）【控制语句】

编写程序，根据输入的分数输出等级。

**规则**：

- 90~100：A
- 80~89：B
- 70~79：C
- 60~69：D
- 0~59：F
- 其他输入：提示非法

**要求**：使用 `switch` 语句（提示：`score / 10`）

**示例输出**：

```
请输入成绩：85
等级：B
```

**答案：**

```c
/* grade.c - 成绩等级判定 */
#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int grade = 0;
    printf("请输入成绩: ");
    scanf("%d", &grade);

    switch (grade / 10) {
        case 10: case 9: printf("A\n"); break;
        case 8: printf("B\n"); break;
        case 7: printf("C\n"); break;
        case 6: printf("D\n"); break;
        default: printf("F\n");

    }

    return EXIT_SUCCESS;
}

```



---

### P10：打印菱形（15 分钟）【控制语句】

输入一个奇数 $n$，打印 $n$ 行的菱形。

**要求**：

- 使用嵌套 `for` 循环
- 先打印上半部分（含中间行），再打印下半部分

**示例输出**（n=5）：

```
    *
   ***
  *****
   ***
    *
```

**答案：**

```c
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
    return 0;
}
```



---

### P11：最大公约数（10 分钟）【控制语句】

编写程序，输入两个正整数，求它们的最大公约数（GCD）。

**要求**：

- 使用辗转相除法（Euclid 算法）
- 使用 `while` 循环

**示例输出**：

```
请输入两个正整数：48 36
最大公约数：12
```

**答案：**

```c
/* gcd.c - 计算两个数的最大公因数 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int a = 0;
    int b = 0;
    printf("请输入两个正整数: ");
    scanf("%d%d", &a, &b);

    printf("gcd(%d, %d) = ", a, b);
    // 假设 a < b;
    if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }


    while (a < b) {
       int r = b % a;
       if (r == 0) {
           break;
       }
       b = a;
       a = r;
    }
    printf("%d\n", a);

    return EXIT_SUCCESS;
}
```



---

### P12：猜数字游戏改进版（20 分钟）【控制语句】

在练习 6 猜数字游戏的基础上改进：

**要求**：

- 程序随机生成 1~100 的数字
- 用户最多猜 7 次
- 每次猜测后提示"大了"或"小了"
- 猜对输出恭喜，7 次用完输出答案
- 使用 `for` 循环 + `break`

**示例输出**：

```
我想了一个 1~100 的数字，你有 7 次机会！
第 1 次猜测：50
大了！
第 2 次猜测：25
小了！
第 3 次猜测：37
恭喜你，猜对了！共猜了 3 次
```

**答案：**

```c
/* guess-number2.c - 猜数字 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

constexpr size_t total_count = 7;

int main(void) {
    // 设置随机数种子
    srand(time(NULL));
    // 1 ~ 100 内的随机数
    int target = rand() % 100 + 1;

    int guess = 0;
    printf("我想了一个 1 ~ 100 的数字，你有 7 次机会!");
    for (size_t i = 0; i < 7; ++i) {
        printf("\n第 %zu 次 猜测: ", i + 1);
        scanf("%d", &guess);
        if (guess < target) {
            printf("小了！");
        } else if (guess > target) {
            printf("大了!");
        } else {
            printf("恭喜你，猜对了！共猜了 %zu 次，剩余 %zu 次\n", i + 1, total_count - i - 1);
            break;
        }
    }

    return EXIT_SUCCESS;
}
```



---

### P13：打印质数（15 分钟）【控制语句】

编写程序，输出 2~100 之间的所有质数。

**要求**：

- 使用嵌套循环（外层遍历数字，内层判断是否为质数）
- 使用 `break` 优化内层循环
- 每行输出 10 个质数

**示例输出**：

```
2 3 5 7 11 13 17 19 23 29
31 37 41 43 47 53 59 61 67 71
73 79 83 89 97
```

**答案：**

```c
/* primes2.c - 输出 N 以内的所有素数以及素数的个数 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return EXIT_FAILURE;
    }

    size_t number = strtoull(argv[1], nullptr, 0);

    size_t count = 3;  // 2 3 5 是已知的素数
    printf("%d %d %d ", 2, 3, 5);
    // 从 7 开始遍历到 number
    for (size_t target = 7, step = 4; target <= number; target = target + step, step = 6 - step) {
        // 对于大于 5 的数，5 的倍数一定不是素数
        if (!(target % 5)) {
            continue;
        }
        bool flag = true;
        // 对于每个 number
        for (size_t factor = 3;  factor * factor <= target; factor = factor + 2) {
            if (!(target % factor)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            if (!(count % 10)) {
                puts("");
            }
            printf("%zu ", target);
            ++count;
        }
    }

    printf("\nThere are a total of %zu prime numbers in %zu\n", count, number);
    return EXIT_SUCCESS;
}
```



---

### P14：数字金字塔（15 分钟）【控制语句】

输入一个正整数 $n$，打印如下数字金字塔。

**要求**：

- 使用嵌套 `for` 循环
- 数字之间用空格分隔，整体居中对齐

**示例输出**（n=5）：

```
    1
   2 2
  3 3 3
 4 4 4 4
5 5 5 5 5
```

**答案：**

```c
/* digital-tower.c - 数字塔 */
#include <stdio.h>
#include <stdlib.h>


size_t digit_count(size_t number) {
    size_t count = 0;
    do {
        ++count;
        number /= 10;
    } while(number != 0);
    return count;
}

int main(void) {

    size_t layer = 0;
    printf("请输入一个正奇数: ");
    scanf("%zu", &layer);
    if (!(layer & 0x1)) {
        fprintf(stderr, "请输入一个奇数!\n");
        return EXIT_FAILURE;
    }

    size_t count = digit_count(layer);

    for (size_t i = 1; i <= layer; ++i) {
        for (size_t j = 0; j < i; ++j) {
            j == 0 ? printf("%*zu", (int)(layer - i + count), i): printf("%*zu", (int)count + 1, i);
        }
        puts("");
    }

    return EXIT_FAILURE;
}
```



---

### P15：Fibonacci 数列（10 分钟）【控制语句】

编写程序，输出 Fibonacci 数列的前 20 项。

**要求**：

- 使用 `for` 循环
- Fibonacci 数列：1, 1, 2, 3, 5, 8, 13, 21, ...
- 每行输出 5 个数

**示例输出**：

```
1 1 2 3 5
8 13 21 34 55
89 144 233 377 610
987 1597 2584 4181 6765
```

**答案：**

```c
/* fibonacci.c - 输出 fibonacci 数列的前 n 项 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 0;
    printf("输出一个正整数: ");
    scanf("%d", &n);
    if (n < 0) {
        fprintf(stderr, "请输入正整数\n");
        return EXIT_FAILURE;
    }

    int pre = 0;
    int next = 1;
    for (int i = 1; i <= n; ++i) {
        printf("%d ", next);

        pre += next;
        next = pre - next;
        pre = pre - next;

        next = pre + next;

        if (!(i % 5)) {
            puts("");
        }
    }
    puts("");

    return EXIT_SUCCESS;
}
```



---

## 三、思考题

### T01【快速入门】

以下代码有什么问题？如何修复？

```c
#define ARRAY_SIZE 10

int main(void) {
    int arr[ARRAY_SIZE];
    for (int i = 0; i <= ARRAY_SIZE; i++) {
        arr[i] = i * 2;
    }
    return 0;
}
```

**答案：** 数组的最大索引是 `ARRAY_SIZE - 1`；`i <= ARRAY_SIZE` 会导致数组越界访问。将 `<=` 修改为 `<` 即可

---

### T02【基本值和数据】

为什么以下代码可能输出意外结果？

```c
double x = 0.1 + 0.2;
if (x == 0.3) {
    printf("相等\n");
} else {
    printf("不相等：%f\n", x);
}
```

**答案：** 输出的结果可能是 `不相等: 0.3xxxxx`。这是应为 `0.1` `0.2` 的二进制表示是无限循环的，无法精确表示。所以 浮点运算会出现精度丢失

---

### T03【快速入门】

解释以下代码中 `const` 的作用：

```c
char const *const str = "hello";
```

**答案：** 限制通过 `str` 修改字符串的内容。同时限制修复 `str` 的指向

---

### T04【控制语句】

以下代码有什么问题？如何修复？

```c
int i = 0;
while (i < 10) {
    if (i == 5) {
        // ++i; // 补上 ++i
        continue;
    }
    printf("%d ", i);
    i++;
}
```

**答案：** 会出现无限循环。因为 `i == 5` 时 `continue` 会跳过剩余的循环体代码，导致 `i` 无法修改始终时 `5`。应该在 `continue` 前补上一个 `++i`;

---

### T05【控制语句】

以下代码的输出是什么？为什么？

```c
for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
        if (j == 3) {
            break;
        }
        printf("(%d,%d) ", i, j);
    }
}
```

`break` 跳出的是哪一层循环？

**答案：** 

+ 输出：`(0,0) (0,1) (0,2) (1,0) (1,1) (1,2) (2,0) (2,1) (2,2) (3,0) (3,1) (3,2) (4,0) (4,1) (4,2)`
+ `break` 退出的是它所在的那一层循环。本题是最内层

---

### T06【控制语句】

以下两种写法有什么区别？哪种更好？

```c
// 写法 A
for (int i = 0; i < n; i++) {
    // ...
}

// 写法 B
int i = 0;
while (i < n) {
    // ...
    i++;
}
```

**答案：**逻辑上没有区别。但是，写法B在离开while 语句后循环变量 `i` 依然可以访问。最好使用写法A

---

## 四、挑战题（选做）

### C01：打印菱形【控制语句】

输入一个奇数 $n$，打印 $n$ 行的菱形。

**示例**（n=5）：

```
    *
   ***
  *****
   ***
    *
```

**答案：**

---

### C02：哥德巴赫猜想验证【控制语句】

验证 4~100 之间的所有偶数都可以表示为两个素数之和。

**输出格式**：

```
4 = 2 + 2
6 = 3 + 3
8 = 3 + 5
...
```

**答案：**

---

### C03：打印日历【控制语句】

输入年份和月份，打印该月的日历。

**要求**：

- 判断闰年（第 1 周已有代码）
- 计算该月 1 号是星期几（可使用蔡勒公式或基姆拉尔森公式）
- 格式对齐，星期日到星期六排一行

**示例输出**（2026 年 7 月）：

```
日 一 二 三 四 五 六
          1  2  3  4
 5  6  7  8  9 10 11
12 13 14 15 16 17 18
19 20 21 22 23 24 25
26 27 28 29 30 31
```

**答案：**

---

### C04：Collatz 猜想【控制语句】

输入一个正整数 $n$，输出从 $n$ 到 1 的 Collatz 序列。

**规则**：

- 如果 $n$ 是偶数，$n = n / 2$
- 如果 $n$ 是奇数，$n = 3n + 1$
- 重复直到 $n = 1$

**要求**：

- 使用 `do-while` 循环
- 统计序列长度
- 输出序列和长度

**示例输出**：

```
请输入一个正整数：6
序列：6 3 10 5 16 8 4 2 1
长度：9
```

**答案：**
