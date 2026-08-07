# break 和 continue 语句

> week01 · C 语言全貌 · 知识点 12

> 状态：☑ 已完成

## 速览

`break` 立即终止整个循环，`continue` 跳过本次迭代剩余代码进入下一次。`break` 像断电，`continue` 像跳过。`for` 中 `continue` 会执行更新表达式，`while`/`do-while` 中直接回到条件检查。`for(;;)` 等价于 `while(true)`。

---

## 是什么

`break` 和 `continue` 这两个关键字在循环内部控制循环的执行；它们是与 `for` `while` `do-while` 是关联在一起的。循环就像是流水线，`break` 和 `continue` 就是用于控制流水线的按钮

---

## 详细解释

`break` 会立即终止它所在的循环，就像直接给流水线断电一样；`break` 一旦执行，循环立即停止，不再检查控制表达式也不再执行 `break` 后面的代码。而是直接跳转到循环体外的下一条语句开始

```c
while (...) {
    ...;
    break;  // ⬅ 循环立即结束
    ....;	// ⬅ break 后面的代码永远不会执行
}
```

`continue` 跳过本次迭代，继续下一次。它不终止循环，只是说 **这次不做了，下一个**

```c
for (size_t i = 0; i < 10; ++i) {
    ...
    continue;   // ← 跳过本次迭代的剩余代码
    ...         // ← 这行不会执行
    // 但 ++i 照常执行，然后重新检查 i < 10
}
```

执行 `continue` 会跳过循环体中的剩余代码。对于 `for` 语句而言，`continue` 会直接去执行条件更新操作(例如 `++i`)，因为它不属于循环体；对于 `while` 和 `do-while` 而言，`continue` 就直接回到条件检查

下表总结了 `break` 和 `continue` 对循环的控制方式以及何时使用

| 关键字     | 做什么                           | 用在               |
| ---------- | -------------------------------- | ------------------ |
| `break`    | 终止整个循环，不再回头           | 达到目标、提前退出 |
| `continue` | 跳过本次迭代剩余代码，进入下一次 | 跳过不合适的迭代   |

《Modern C》中的演示 `break` 例子还是 Heron 近似，但是它把条件从 `while` 的控制表达式移到循环体内部

```c
while (true) {
    double prod = a * x;
    if (fabs(1.0 - prod) < ε) {   // 精度够了吗？
        break;                      // 够了 → 跳出
    }
    x *= (2.0 - prod);             // 不够 → 继续逼近
}
```

这种写法的好处是把"计算-判断-更新"三步拆开，逻辑更清晰。`while (true)` 表示"理论上无限循环"，但 `break` 在合适的时候终止它

> [!NOTE]
>
> `for` 循环可以任意省略位于 `(...)` 中的三部分，但是每个部分之间的分号(`;`)必须保留。
>
> ```c
> for (;;) {
>     ...;
>     if (条件) break;
>     ...;
> }
> ```
>
> 如果 `for` 的控制表达式省略时被解释为 **"永远为真"**，与 `while(true)` 等价的。至于选择哪一个取决于人类程序员编写程序的风格和爱好

《Modern C》中的演示 `continue` 例子也是是 Heron 近似的扩展：加一个检查，如果 `x` 跑到了 $1$ 的另一侧就先调整回来

```c
for (size_t i = 0; i < max_iterations; ++i) {
    if (x > 1.0) {          // 跑到 1 的右边去了
        x = 1.0 / x;        // 拉回左边
        continue;           // 跳过这次迭代的逼近计算
    }
    double prod = a * x;
    if (fabs(1.0 - prod) < error) break;
    x *= (2.0 - prod);
}
```

## 代码示例

`heron2.c` — 使用 Heron 近似计算 $\frac{1}{x}$ 的值。添加最大迭代次数避免无限循环

```c
/* heron2.c — while 语句：使用 Heron 近似计算 1 / x 的值 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 下限和上限迭代限制以 1.0 左右为中心
static double const eps1m01 = 1.0 - 0x1P-01;  // 1.0 - 1 * 2^{-1} = 1 - 0.5
static double const eps1p01 = 1.0 + 0x1P-01;  // 1.0 + 1 * 2^{-1} = 1 + 0.5
static double const eps1m24 = 1.0 - 0x1P-24;  // 1.0 - 1 * 2^{-24}
static double const eps1p24 = 1.0 + 0x1P-24;  // 1.0 + 1 * 2^{-24}

int main(int argc, char* argv[argc + 1]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <a>  <max-iter>\n", argv[0]);
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
    // Heron 近似求解
    for (size_t i = 0; i < max_iter; ++i) {
        double prod = yn * a;
        // 检查当前迭代目标值是否满足精度要求
        if (prod < eps1m24 || eps1p24 < prod) {
            yn *= 2.0 - prod;
        } else {
            break;
        }
    }
    printf("heron: a=%.5e,\tyn=%.5e\ta * yn = %.12f\n", a, yn, a * yn);
    return EXIT_SUCCESS;
}
```
