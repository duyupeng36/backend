# Modern C 笔记：ch05-基本值与数据（下）——二进制表示

> 章节：第 5 章 · Basic Values and Data（基本值与数据）  
> 日期：2026-07-26  
> 状态：☑ 已完成（第二部分 10-18）

---

## 📋 速览

无符号整数是模 2^p 的环，位运算符（\|、&、^、~）提供了集合操作视角，移位运算（<<、>>）连接了数值和位集合。有符号整数使用补码：正值表示与无符号一致，~A+1 = -A，溢出是 UB。定宽类型（uint32_t 等）提供精确宽度，_BitInt（C23）支持任意位数。浮点数据由符号-指数-尾数三部分组成，精度有限，运算不满足结合律/交换律/分配律——大数吞小数，永远不直接比较相等。

---

### 知识点 10：命名常量

**是什么**

本质上来讲，C 程序中只有一种常量就是字面量。但是，在程序中我们不应该直接使用字面量（称为 **魔法数**）；使用语言提供的能力给字面量赋予一个名字可以极大的提供程序的可读性和可扩展性

**详细解释**

来看一个使用魔法数的例子

```c
// ❌ 糟糕的代码：魔法数字
char const *const bird[3] = { "raven", "magpie", "jay" };
char const *const pronoun[3] = { "we", "you", "they" };
char const *const ordinal[3] = { "first", "second", "third" };

// 这里的 3 是什么含义？
for (unsigned i = 0; i < 3; ++i) { 
	printf("Corvid %u is the %s\n", i, bird[i]);
} 
```

数字 $3$ 在代码中出现了多次，但它们的含义各不相同。如果需要添加一种鸟类，需要修改多处代码。为零提供程序的可读性和可维护性，我们应该遵守两条规则

> 1. 所有具有特定含义的常量必须命名
> 2. 所有含义不同的常量必须区分

**运行时常量 vs 编译时常量**：真正意义上的常量是 **编译时常量**，值在编译时就固定了；后续无法通过其他方式修改。运行时常量本质上是只读对象，值在运行时确定；C 语言特性允许我们绕过对象的只读属性从而修改它

关键字 `const` 用作类型限定符，表示某个类型的对象在运行时只读的。也就是说，`const` 对象是只读对象，其值要在运行时才会确定。例如

```c
extern double const factor; // 只读对象，值未知（运行时才链接）
```

`const` 关键字常用于声明接口。例如，计算字符串长度的接口 `strlen` 中的参数 `char const* s`：指针 `s` 指向的是一个只读的 `char` 对象

```c
size_t strlen(char const* s);
```

在 C23 标准之前，编译时常量只有 **字面量** 一种，以及通过预处理指令 `#define` 定义的对象式宏。C23 标准引入 `constexpr` 关键字，用于创建带类型属性的编译时常量对象

```c
constexpr double pi = 3.1415926; // C23：真正意义上的常量对象
```

> [!WARNING]
>
> 在 C 语言中，出于历史原因，字符串字面量的类型是 `char[]` 而不是 `char const[]`。但是，字符串字面量是存储在**只读内存**中，任何试图修改字符串字面量的动作都是未定义行为。当然，声明字符指针指向字符串字面值时，我们应该使用 `char const*` 类型；这种类型限制提升的操作编译器是允许的也是推荐的

使用**对象式宏**也是创建编译时常量的一种方式。然而，对象式宏仅仅只是**简单的文本替换**（将宏名出现的地方简单的插入替换文本），在预处理阶段就完成了。这意味着，在程序调试时完全无法获得对象式宏的任何信息。

```c
#define 宏名 替换文本
```

> [!TIP]
>
> C 标准库和一些开源软件中，宏名通常是全大写的。我们在定义宏时也应该遵守这个规则。从 C23 标准起，对象式宏应该少用，而是使用 `constexpr` 定义带有类型的编译时对象

对于整数类型的常量，除了 `constexpr` 关键字之外，使用 `enum` 才是正解。例如

```c
enum corvid { magpie, raven, jay, corvid_num, };
// magpie=0, raven=1, jay=2, corvid_num=3（自动递增）
```

然后就可以使用 `corvid_num` 魔法数字 $3$

```c
char const*const bird[corvid_num] = {
    [raven]  = "raven",
    [magpie] = "magpie",
    [jay]    = "jay",
};
```

>  [!TIP]
>
> 好处：需要新增一种鸟时只需在 `enum` 里加一个元素（放在 `corvid_num` 之前），数组长度自动跟着变，所有用 `corvid_num` 的地方都不需要改

默认情况下，枚举列表中的第一个值是整数 $0$，随后的每个枚举的值都是前一个枚举值加 $1$；这种由编译器根据枚举列表分配的枚举常量称为 **位置值**。当然，我们可以显示指定枚举的值

```c
enum flags {
    FLAG_A = 1,
    FLAG_B = 2,
    FLAG_C = 4,
    FLAG_D = 8
};
```

> [!WARNING]
>
> 注意，如果枚举列表的中的所有枚举值类型依据整数字面量类型推断。换句话说，如果枚举列表的中的所有枚举值都可以放入 `signed int`，那么它们的类型就是 `signed int`

从 C23 标准开始，允许我们显示指定底层类型。通常情况下，应该在枚举常量可能超出 `signed int` 范围，显式指定底层类型

```c
// 自动调整底层类型
enum wide {
    minimal = LONG_MIN,
    maximal = LONG_MAX
};

// 显式指定底层类型
enum wider : long {
    minimer = LONG_MIN,
    maximer = LONG_MAX
};

// 指定无符号类型
enum e32 : uint32_t {
    d32 = 0,
    u32 = 0xFFFF'FFFF
};
```

> [!TIP]
>
> 在 C 语言中，**整数常量表达式（Integer Constant Expression，ICE）**就是由一系列编译时出常量组成，可以在编译期完成计算的表达式。既然枚举是整数常量，那么枚举列表中的枚举值必须是 ICE
> 
> ```c
> signed const o42 = 42;       // o42 是对象，不是常量
> constexpr signed c42 = 42;   // c42 是命名常量
>
> enum {
>     b42 = 42,          // ✅ 42 是字面量
>     c52 = o42 + 10,    // ❌ 错误！o42 是对象
>     b52 = b42 + 10,    // ✅ b42 是枚举常量
>     d52 = c42 + 10,    // ✅ c42 是 constexpr
> };
> ```


**代码示例**

```c
/* named_constants.c — 魔法数 vs 命名常量 vs enum */
#include <stdio.h>

// ❌ 魔法数方式
char const*const bird_bad[3] = { "raven", "magpie", "jay" };

// ✅ enum 方式：新增强后只需在 enum 中添加
enum corvid { magpie, raven, jay, corvid_num, };
char const*const bird[corvid_num] = {
    [raven]  = "raven",
    [magpie] = "magpie",
    [jay]    = "jay",
};

int main(void) {
    // 用 corvid_num 替代裸 3
    for (unsigned i = 0; i < corvid_num; ++i)
        printf("bird[%u] = %s\n", i, bird[i]);

    // 枚举值由位置决定
    printf("magpie=%d, raven=%d, jay=%d, corvid_num=%d\n",
           magpie, raven, jay, corvid_num);

    // C23 constexpr 编译时常量
    constexpr double pi = 3.14159265358979;
    printf("pi = %.10f\n", pi);
}
```

**练习**

- [x] **练习 1**：以下哪些是编译时常量、哪些是运行时常量（只读对象）？

  ```c
  42							// 答案：编译时常量
  const int x = 10;			// 答案：只读对象
  constexpr double pi = 3.14;	// 答案：编译时常量
  "hello"						// 答案：答案：编译时常量
  extern double const factor;	// 答案：运行时常量
  ```

- [x] **练习 2**：`enum` 值推导 — `enum suit { CLUBS, DIAMONDS=3, HEARTS, SPADES, };` 中各枚举的值分别是多少？
    答案：`CLUBS == 0` `DIAMONDS == 3` `HEARTS == 4` `SPADES == 5`

- [x] **练习 3**：完整程序 — 用 `enum` 定义一个"星期"类型（7 个值），配合指定初始化器创建星期的中英文名称数组，输入 0-6 打印对应名称，保存到 `code/ch05/weekday_enum.c`

---

### 知识点 11：复合字面量

**是什么**

C99 标准引入了一种**创建临时对象**的字面量，称为 **复合字面量**

**详细解释**

复合字面量的语法形式是 `(T){ INIT }`；即一个用括号将类型括起来，后跟一个初始化器。下面是一个例子：

```c
#define CORVID_NAME /**/                 \
(char const*const[corvid_num]){          \
  [chough] = "chough",                   \
  [raven] = "raven",                     \
  [magpie] = "magpie",                   \
  [jay] = "jay",                         \
}
```

有了它，我们可以省略 `bird` 数组并重写我们的 `for` 循环

```c
for (unsigned i = 0; i < corvid_num; ++i) {
    printf("Corvid %u is the %s\n", i, CORVID_NAME[i]);
}
```

> [!WARNING]
>
> 注意：
>
> + **复合字面量定义一个对象而不是编译时常量**。虽然我们的演示例子将他定义为对象式宏
> + 既然不是编译时常量，复合字面量就不适合 ICE
> + 复合字面量的类型 `T` 应当是 `const` 修饰的。字面量不应该去修改它

从 C23 标准起，复合字面量的类型允许使用 `constexpr` 进行修饰，这样带来了下面的两个优势：

+ 编译时检查：值必须精确匹配类型
+ 优化机会：编译器知道数据不会改变

```c
#define CORVID_NAMES /* */ \
    (constexpr char[8][corvid_num]){ \
        [chough] = "chough", \
        [raven] = "raven", \
        [magpie] = "magpie", \
        [jay] = "jay", \
    }
```

**代码示例**

```c
/* compound_literal.c — 复合字面量 vs 命名数组 */
#include <stdio.h>

enum corvid { magpie, raven, jay, chough, corvid_num, };

int main(void) {
    // 方式一：命名数组
    char const*const bird[corvid_num] = {
        [raven]  = "raven",
        [magpie] = "magpie",
        [jay]    = "jay",
    };

    // 方式二：复合字面量，无需先声明变量
    for (unsigned i = 0; i < corvid_num; ++i)
        printf("%s\n", (char const*const[corvid_num]){
            [raven]  = "raven",
            [magpie] = "magpie",
            [jay]    = "jay",
        }[i]);
}
```

**练习**

- [x] **练习 1**：复合字面量创建临时数组 — `(int[3]){ 1, 2, 3 }[1]` 的值是多少？
    答案: 获取索引为 1 的元素，值是 2

- [x] **练习 2**：复合字面量是对象还是常量？能用作数组长度吗？（`int arr[(int[1]){5}[0]];` 合法吗？）
    答案：复合字面量是对象；不应该用作数组长度（C99后支持变长数组可以）。

- [x] **练习 3**：完整程序 — 用复合字面量配合 `enum`，不声明任何数组变量，直接打印 4 种乌鸦的名字，保存到 `code/ch05/compound_corvid.c`

---

### 知识点 12：无符号整数的二进制表示

**是什么**

类型的二进制表示是一个描述该类型可能值的模型：二进制表示桥接了类型和值；它于该类型对象的表示不同。现在，我们来看无符号整数的二进制表示

**详细解释**

在 [表达式](ch04-expressions.md) 中我们学习过 `size_t` 上的 `+` `-` `*` 都是模 `SIZE_MAX + 1` 运算。现在，我们把它推广到所有无符号整数类型上

一个无符号类型值的集合是 $\{0,1, 2, \cdots,2^p-1\}$，其中 $p$ 称为精度。对于无符号类型，精度 $p$ 就是类型的尺寸

> [!TIP]
>
> 任何无符号整数类型的最大值都是 $2^p - 1$ 的形式。对于 `INT_WIDTH == 32` 的平台上，`unsigned int` 类型的最大值 `UINT_MAX` 的值就是 $2^{32}-1$ 。`UINT_MAX` 来自于头文件 `<limits.h>`
>
> | 无符号类型           | 最大值       |
> | -------------------- | ------------ |
> | `unsigned int`       | `UINT_MAX`   |
> | `unsigned long`      | `ULONG_MAX`  |
> | `unsigned long long` | `ULLONG_MAX` |

非负整数值的二进制表示由称为 **位** 的二进制数字 $(b_{p-1}b_{p-2}\cdots b_{2}b_{1}b_0)_2$ 表示；它对应值的计算公式如下
$$
\text{Value} = \sum_{i=0}^{p-1}b_{i}\times2^{i}
$$
在该二进制表示中的值 $p$ 称为基础类型的**精度**；$b_{0}$ 称为最低有效位（least-significant bit，LSB）；$b_{p-1}$ 称为最高有效位（most-significant bit，MSB）

> [!TIP]
>
> C 为每个无符号类型提供了精度宏，它们都是以 `_WIDTH` 结尾的。`UINT_WIDTH` 是 `unsigned int` 类型的精度；`ULONG_WIDTH` 是 `unsigned long` 类型的精度。这些宏和对应的 ``_MAX` 宏配合使用（比如 `UINT_MAX`），可以完全描述一个无符号类型的行为

**代码示例**

```c
/* unsigned_bits.c — 无符号整数的位模式和精度 */
#include <stdio.h>
#include <limits.h>

int main(void) {
    // 精度和最大值的关系：2^p - 1
    printf("UINT_WIDTH  = %d, UINT_MAX  = %u  (2^%d - 1)\n",
           UINT_WIDTH, UINT_MAX, UINT_WIDTH);
    printf("ULONG_WIDTH = %d, ULONG_MAX = %lu\n\n",
           ULONG_WIDTH, ULONG_MAX);

    // 展示值 240 的位模式（16 位精度下）
    unsigned short val = 240;
    printf("240 的二进制 (16 位): ");
    for (int i = UINT_WIDTH - 1; i >= 0; --i)  // 从 MSB 到 LSB
        printf("%d", (val >> i) & 1);
    printf("\n");

    // LSB 测试：最低有效位是 0 还是 1？
    printf("240 & 1 = %d (LSB)\n", val & 1);
    // MSB：最高有效位（对 unsigned short，精度 16，MSB 是 bit15）
    printf("240 & 0x8000 = %d (MSB)\n", (val & 0x8000) != 0);
}
```

**练习**

- [x] **练习 1**：精度判断 — 在 `UINT_WIDTH == 32` 的平台上，`unsigned int` 能表示的最大值是多少？最小值呢？
    答案：最大值 $2^{32}-1$。最小值 $0$

- [x] **练习 2**：位模式 — 值 `0` 和值 `UINT_MAX` 的二进制位模式分别是什么？（用 0/1 描述）
    答案：值 $0$ 的位模式：$(00\cdots00)_{2}$ 共 $32$ 个 $0$；值 `UINT_MAX` 的位模式：$(11\cdots11)_{2}$ 共 $32$ 个 $1$

- [x] **练习 3**：完整程序 — 写一个程序，打印任意 `unsigned` 值的二进制位模式（从 MSB 到 LSB），保存到 `code/ch05/print_binary.c`

---

### 知识点 13：位运算符 — `&` `|` `^` `~`

**是什么**

无符号整数可以解释为 **位集合**（bit set）：位 $b_i = 1$ 表示元素 $i$ 在集合中。C 语言提供了 $4$ 种专用于操作位的运算符称为 **位运算符**

| 运算符 | 集合运算        | 含义     | 示例    |
| ------ | --------------- | -------- | ------- |
| `|`    | $A \cup B$      | 并集(位或) | `A | B` |
| `&`    | $A \cap B$      | 交集(位与) | `A & B` |
| `^`    | $A \Delta B$    | 对称差集(异或) | `A ^ B` |
| `~`    | $V \setminus A$ | 补集(按位取反) | `~A`    |


**详细解释**

我们直接通过例子来看这几个位运算符是如何操作位的

```c
A = 240         // 二进制: 	 1111 0000  → 集合 {4, 5, 6, 7}
B = 287         // 二进制: 0001 0001 1111  → 集合 {0,1,2,3,4,8}

A | B  = 511    // 并集（union）     {0,1,2,3,4,5,6,7,8}
A & B  = 16     // 交集（intersection）{4}
A ^ B  = 495    // 对称差（XOR）     {0,1,2,3,5,6,7,8}
~A     = 65295  // 补集（complement）{0,1,2,3, 8,9,...,15}  依赖于精度 p
```

> [!TIP]
>
> 按位取反运算符 `~` 与算术取负运算符 `-` 完全不同。`-240 = 65296` 和 `~240 = 65295`相差$1$；相差 $1$ 的原因留在后续介绍有符号数的二进制表示时回答

位操作的实践用法通常就是下面三种

```c
#define FLOCK_MAGPIE  1U    // 0001
#define FLOCK_RAVEN   2U    // 0010
#define FLOCK_JAY     4U    // 0100
#define FLOCK_CHOUGH  8U    // 1000

unsigned flock = 0;
flock |= FLOCK_JAY;            // 设置标志
if (flock & FLOCK_CHOUGH)      // 检查标志
    do_something();
flock &= ~FLOCK_JAY;           // 清除标志
```

**代码示例**

```c
/* bitwise_ops.c — 位运算符演示 */
#include <stdio.h>

int main(void) {
    unsigned A = 240;   // 0b11110000
    unsigned B = 287;   // 0b000100011111

    printf("A     = %3u (0x%02X)\n", A, A);
    printf("B     = %3u (0x%02X)\n", B, B);
    printf("A | B = %3u (0x%02X)  并集\n", A | B, A | B);
    printf("A & B = %3u (0x%02X)  交集\n", A & B, A & B);
    printf("A ^ B = %3u (0x%02X)  对称差\n", A ^ B, A ^ B);
    printf("~A    = %3u (0x%02X)  补集\n", ~A, ~A & 0xFFFF);

    // 标志位用法
    unsigned flags = 0;
    flags |= 4U;                       // 设置 bit 2
    printf("\nflags = %u\n", flags);
    printf("bit 2 设置? %d\n", (flags & 4U) != 0);
    flags &= ~4U;                      // 清除 bit 2
    printf("bit 2 清除后: %u\n", flags);
}
```

**练习**

- [x] **练习 1**：位运算结果 — `0b1010 | 0b0101` 和 `0b1100 & 0b1010` 的值各是多少？
    答案：`0b1010 | 0b0101 == 0b1111` 和 `0b1100 & 0b1010 == 0b1000` 

- [x] **练习 2**：标志位操作 — 用 `unsigned` 实现一个 3 位标志：bit0=已读，bit1=已回复，bit2=已归档。写出设置、检查、清除每种标志的表达式

    ```c
    unsigned int value = 0;
    // 1. 设置 bit0			bit1					bit2
    value |= 0x1U;		value |= (0x1U << 1);	value |= (0x1U << 2);	
    // 2. 检查 bit0			bit1					bit1
    value & 0x1U;		value & (0x1U << 1);	value & (0x1U << 2);
    // 3. 清除 bit0			bit1					bit1
    value & (~ 0x1U);	value & (~(0x1U << 1));	value & (~(0x1U << 2));	
    ```

    

- [x] **练习 3**：完整程序 — 用位运算实现一个简单的权限系统（读=4, 写=2, 执行=1），输入权限值，打印该权限下允许哪些操作，保存到 `code/ch05/permission_bits.c`

---

### 知识点 14：移位运算符 — `<<` `>>`

**是什么**

**左移 `<<`** $n$ 位相当于乘以 $2^n$；**右移 `>>`**  $n$ 位相当于除以 $2^n$（向下取整）；也就是说，移位运算符连接了无符号整数的数值解释和位集合解释。

**详细解释**

直接来看移位运算符的例子：加上变量 `A` 是 $16$ 位的无符号整数。**左移** 从集合的视角看就是将集合中的每个值加上 $n$（$n$ 是左移的位数）

```c
// 左移：乘以 2^n；从集合的观点上看，就是对集合中中每个元素加上 n
A = 240;    // 240 → {4, 5, 6, 7}
A << 2;     // 240 × 4 = 960 → {6, 7, 8, 9}
A << 9;     // 溢出！位 16 被丢弃
            // 结果：57344 → {13, 14, 15}

A = 240;           // {4, 5, 6, 7}
A >> 2;            // 60 → {2, 3, 4, 5}
                   // 240 ÷ 4 = 60
```

**右移** 从集合的视角看就是将集合中的每个值减去上 $n$（$n$ 是右移的位数）

```c
A = 240;           // {4, 5, 6, 7}
A >> 2;            // 240 ÷ 4 = 60 → {2, 3, 4, 5}
```

> [!WARNING]
>
> 在位移动的过程中，如果集合中的元素值超过了当前表示范围，则会被丢弃（**溢出**）。假设在 `unsigned` 类型上进行移位运算；最多移动 `INT_WIDTH - 1` 位

> [!WARNING]
>
> **移位的位数必须严格小于类型的精度。** `x << 32`（当 `UINT_WIDTH == 32` 时）是未定义行为——结果不是 0，而是程序可能崩溃。这条规则对 `<<` 和 `>>` 都适用。

**代码示例**

```c
/* shift_ops.c — 移位运算符演示 */
#include <stdio.h>
#include <limits.h>

int main(void) {
    unsigned A = 240;   // 0b0000000011110000

    // 左移 = 乘以 2^n
    printf("A << 2 = %u (240 × 4)\n", A << 2);      // 960
    printf("A << 4 = %u (240 × 16)\n", A << 4);     // 3840

    // 右移 = 除以 2^n（向下取整）
    printf("A >> 2 = %u (240 ÷ 4)\n", A >> 2);      // 60
    printf("A >> 4 = %u (240 ÷ 16)\n", A >> 4);     // 15

    // 左移溢出：高位被丢弃
    // 240 << 12: bit 4-7 移到 bit 16-19 → 超出 16 位范围 → 丢弃
    unsigned short B = 240;
    printf("240 << 12 (16-bit) = %u\n", B << 12);

    // 不能移超过精度！以下是未定义行为：
    // unsigned x = 1; x << UINT_WIDTH;  // UB!
}
```

**练习**

- [x] **练习 1**：移位计算 — `1 << 3`、`128 >> 2`、`1024 >> 5` 各是多少？
    答案: `1 << 3` = $1 \\times 2^3 = 8$; `128 >> 2` = $128 \\div 2^2 = 32$; `1024 >> 5` = $1024 \\div 2^5=32$

- [x] **练习 2**：移位边界 — 对于 `unsigned int`（UINT_WIDTH=32），`1 << 31` 合法吗？`1 << 32` 呢？为什么？
    答案：`1 << 31` 合法，刚好到达最高有效位。`1 << 32` **未定义行为**（移位数等于精度，不是得到 0）

---

### 知识点 15：有符号整数的表示

**是什么**

有符号整数比无符号整数复杂，涉及两个问题：**溢出时发生什么？** 和 **符号如何表示？** 从 C23 标准开始，有符号整数只能使用 **二进制补码** 表示

> [!WARNING]
>
> 历史上负数的表示方法有 $3$ 种：原码（sign-magnitude）、反码（ones' complement）、补码（two's complement）。C23 标准正式移除了前两种有符号整数的表示

**详细解释**

二进制补码表示与无符号表示类似，唯一区别就是将最高有效位(Most Significant Bit, MSB)解释为 **负权**

$$
\text{value} = -b_{p-1}\cdot 2 ^{p-1} + \sum_{i=0}^{p-2} b_i \cdot 2^i
$$

比较无符号和有符号整数的表示形式，我们可以发现：**非负值的位模式完全一样**；所以，`INT_MAX` 的值也是 $2^{p-1}-1$（最高位多用于表示负权，把数值空间分成了两半）

> [!TIP]
>
> 下面我们来介绍二进制补码的原理。对于 $n$ 位 $r$ 进制数，规定
>
> + $r^n - a$ 称为 $r$ 进制数 $a$ 的关于 **基数的补数**($r$ 的补数)
> + $r^n - 1 -a$ 称为 $r$ 进制数 $a$ 的关于 **减基数的补数**($r-1$的补数，也称 **减补数**)
>
> 如果数 $a$ 是 $n$ 位的 $r$ 进制数，将按照各个数位展开有
>
> $$
> \begin{aligned}
> a &= a_{n-1}r^{n-1} + a_{n-2}r^{n-2} + \cdots + a_{1}r^{1} + a_{0}r^{0}\\
> &= \sum_{i=0}^{n}a_i\cdot r^i
> \end{aligned}
> $$
>
> 根据 $r$ 的补数的定义，我们有
>
> $$
> \begin{aligned}
> a + b &= r^n \\
> \sum_{i=0}^{n}a_i\cdot r^i + b &= r^n\\
> &=\sum_{i=0}^{n-1}(r-1)^i + 1\\
> b &= \sum_{i=0}^{n-1}(r-1)^i - \sum_{i=0}^{n}a_i\cdot r^i  + 1\\
> &= \sum_{i=0}^{n-1}(r - 1 - a_i)r^i + 1
> \end{aligned}
> $$
>
> 也就是说，$r$ 的补数的计算方式就是用 $r-1$ 减去 $a$ 的每一位后再加 $1$。当 $r = 2$ 时，此时基数的补数就是 **二补数**，也就是我们常说的 **补码**
>
现在应该很清晰了 `-240u = 65296` 和 `~240u = 65295` 相差 $1$ 的原因：`-240` 的位模式就是 `~240 + 1` 的位模式

> [!WARNING]
>
> 警告：有符号整数的溢出是未定义行为。编译器可以采取自己的方式处理有符号整数的溢出。

例如，教材中这个经典演示：

```c
for (signed i = 1; i; ++i)    // 编译器假设溢出永远不会发生
    do_something();            // → 优化成 while(true) 死循环！
```

**未定义行为不是"行为古怪"**。教材对 UB 的定义更精确：

> 一旦程序进入未定义状态，就不再能对执行做任何假设。不是"这个操作的结果不确定"——而是**整个程序的有效性被彻底破坏**。

关键：UB 最危险的地方不是它会崩溃——而是**它可能看起来一切正常**。程序在某台机器上跑了三年没问题，换了个编译器版本突然炸了。

> [!TIP]
>
> 补码有一个不对称性：负方向比正方向多一个值（如 8 位有符号 [-128, 127]）。因此 **`INT_MIN < -INT_MAX`** 始终成立，而且 **`-INT_MIN` 本身就是溢出**（未定义行为）。

> [!TIP]
>
> **位操作应该用无符号类型。** 有符号类型的位移、按位取反等操作受实现定义或 UB 影响——不要在有符号数上玩位运算。

**代码示例**

```c
/* signed_repr.c — 有符号补码表示和 INT_MIN 不对称 */
#include <stdio.h>
#include <limits.h>

int main(void) {
    // 正值在有无符号下位模式相同
    unsigned u = 240;
    signed   s = 240;
    printf("u=240: %u, s=240: %d (同一块内存解释不同)\n", u, s);

    // 补码：-A = ~A + 1
    printf("~240 + 1 = %u (= -240 的无符号表示)\n", ~240u + 1);

    // INT_MIN 的不对称性
    printf("\nINT_MAX  = %d\n", INT_MAX);
    printf("INT_MIN  = %d\n", INT_MIN);
    printf("INT_MIN < -INT_MAX: %d\n", INT_MIN < -INT_MAX);
    // -INT_MIN 是 UB，不要写！
}
```

**练习**

- [x] **练习 1**：补码计算 — 8 位有符号下，值 -1 和 -128 的二进制位模式分别是什么？（用补码公式验证）
    答案: `-1` 的 8 位位模式是 `0b11111111`；`-128` 的 8 位位模式是 `0b10000000`

- [x] **练习 2**：`~A + 1` — 对于 `unsigned short A = 0`，`~A + 1` 的值是多少？这个值和 `-A` 有什么关系？
    答案：假设 `unsigned short` 占 $16$ 位 `~0 + 1 == 2^{16} - 1 + 1` 溢出了，最终结果还是 $0$。`-0` 还是 $0$ 。`~A + 1 == A` 只有在没有溢出的前提下才会满足    

- [x] **练习 3**：`INT_MIN` 陷阱 — 为什么 `int x = INT_MIN; x = -x;` 是未定义行为？
    答案：`abs(INT_MIN) - abs(INT_MAX) == 1` 推出 `-INT_MIN > INT_MAX` 出现溢出；有符号整数溢出是未定义的行为 

---

### 知识点 16：定宽整数类型

**是什么**

标准库提供的具有固定位模式宽度的整数类型，它们不会应为平台和编译器的不同而不同。

**详细解释**

标准整数类型的宽度因平台而异。`<stdint.h>` 头文件中提供了精确宽度的类型

| 类型       | 宽度  | 范围               |
| ---------- | ----- | ------------------ |
| `uint8_t`  | 8 位  | $[0, 255]$           |
| `uint16_t` | 16 位 | $[0, 65535]$         |
| `uint32_t` | 32 位 | $[0, 2^{32}-1]$ |
| `uint64_t` | 64 位 | $[0, 2^{64}-1]$         |
| `int8_t`   | 8 位  | $[-128, 127]$        |
| `int16_t`  | 16 位 | $[-32768, 32767]$    |
| `int32_t`  | 32 位 | $[-2^{31}, 2^{31}-1]$      |
| `int64_t`  | 64 位 | $[-2^{63}, 2^{63}-1]$      |

> [!TIP]
>
> `uintN_t` 恰有 N 位宽度，精度也是 N；`intN_t` 恰有 N 位宽度，但精度是 N−1（因为一位用作符号）。

`<stdint.h>` 头文件中提供了一些宏定义，它们表示这些固定宽度整数类型的源信息

```c
#include <stdint.h>

// 宽度
UINT32_WIDTH  // 32
INT64_WIDTH   // 64

// 范围
UINT32_MAX    // 4294967295
INT64_MIN     // -9223372036854775808
INT64_MAX     // 9223372036854775807

// 字面量宏
UINT64_C(42)  // 42ULL（取决于平台）
```

**C23 `wN` 格式说明符**——不用再猜 `%lu` 还是 `%llu`：

```c
uint32_t n = 78;
printf("%w32u\n", n);      // w32 自动适配 uint32_t
int64_t big = INT64_MAX;
printf("%w64d\n", big);    // w64 自动适配 int64_t
```

**代码示例**

```c
/* fixed_width.c — 定宽整数类型和 wN 格式 */
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void) {
    uint32_t n = 78;
    int64_t big = INT64_MAX;

    // C23 wN 格式说明符
    printf("n is %w32u, big is %w64d\n", n, big);

    // 传统方式（C23 之前）
    printf("n is %" PRIu32 ", big is %" PRId64 "\n", n, big);
}
```

**练习**

- [x] **练习 1**：类型选择 — 以下场景分别选哪种定宽类型？

  ```
  (a) 存储 IPv4 地址（4 字节）		# 答案：uint32_t
  (b) 存储文件大小（最大可能超过 4GB）	# 答案: uint64_t
  (c) 存储一个 8 位传感器的读数		  # 答案: uint8_t
  ```

- [x] **练习 2**：精度 vs 宽度 — `int32_t` 的宽度和精度各是多少？最大值呢？
    答案：宽度是 32，精度是 31。最大值是 $2^{31} - 1$

- [x] **练习 3**：`wN` 格式 — 写一个小程序，用 C23 的 `%wN` 格式打印 `uint16_t`、`uint32_t`、`int64_t` 三种定宽类型变量，保存到 `code/ch05/fixed_width_demo.c`

---

### 知识点 17：精确定位宽整数 `_BitInt`（C23）

**是什么**

C23 标准加入的一个基本类型 `_BitInt(N)` 用于定义宽度为 $N$ 的整数

**详细解释**

定宽类型（`uint32_t` 等）只有 8、16、32、64 几种。如果你需要"恰好 3 位"或"恰好 7 位"的无符号整数——比如模拟一个硬件寄存器——C23 的 `_BitInt`就是答案

```c
unsigned _BitInt(3) u3 = 7wbu;   // 值范围 0..7，3 位
signed   _BitInt(3) s3 = 3wb;    // 值范围 -4..3，3 位
         _BitInt(3) s3 = 3wb; 	 // signed 可省略
```

当然，C23 也为 `_BiInt` 提供了字面值后缀 `wb`。编译器会自动推导所需的最小宽度

```c
7wbu    // 值 7，需要 3 位无符号 → unsigned _BitInt(3)
3wb     // 值 3，需要 2 位 + 1 符号位 → signed _BitInt(3)
3wbu    // 值 3，不需要符号位 → unsigned _BitInt(2)
```

> [!WARNING]
>
> `_BitInt` 进行算术运算时，按最宽的操作数进行。例如
>
> ```c
> unsigned _BitInt(3) u3 = 7wbu;   // 值范围 0..7，3 位
> u3 + 1wbu;	// u3 宽度是 3，1wbu 的宽度是 1 → 结果 unsigned _BitInt(3)
> 			// 7+1 = 8 → 回绕为 0（和 size_t 一样的方式）
> ```

头文件 `<limits.h>` 中定义的宏 `BITINT_MAXWIDTH` 告诉你平台支持的最大 `_BitInt` 宽度，至少应该是 `ULLONG_WIDTH`

```c
constexpr unsigned _BitInt(3) max3u = -1;   // 0b111 
constexpr unsigned _BitInt(4) max4u = -1;   // 0b1111
constexpr   signed _BitInt(4) min4s = ~max4s; // 0b1000 
```

`-1` 赋值给无符号会回绕得到全 $1$ 的位模式；这种写法在定义位掩码时特别简洁。

**代码示例**

```c
/* bitint_demo.c — _BitInt 精确宽度演示 */
#include <stdio.h>
#include <limits.h>

int main(void) {
    // 3 位无符号：0..7，溢出回绕
    unsigned _BitInt(3) u3 = 7wbu;
    printf("u3 = %d, u3 + 1 = %d (回绕!)\n", u3, u3 + 1wbu);

    // 3 位有符号：-4..3
    signed _BitInt(3) s3 = 3wb;
    printf("s3 = %d, s3 + 1 = %d\n", s3, s3 + 1wb);

    // constexpr 精确位掩码
    constexpr unsigned _BitInt(4) mask = -1;   // 0b1111
    printf("mask = 0x%X\n", mask);

    printf("BITINT_MAXWIDTH = %d\n", BITINT_MAXWIDTH);
}
```

**练习**

- [x] **练习 1**：宽度推导 — 字面量 `42wb` 的类型是什么？（提示：42 = 0b101010）
    答案：`_BitInt(7)` 最高位是符号位

## 🤔 疑问记录

| 编号 | 疑问 | 状态 |
|------|------|------|
| 1 | 位运算符的"位集合"视角：`|` = 并集，`&` = 交集，`^` = 对称差，`~` = 补集。这个视角在实际编程中还适用于哪些场景（除了标志位）？ | ☐ 待解答 |
| 2 | `INT_MIN < -INT_MAX` 且 `-INT_MIN` 是 UB——补码的不对称性在哪些算法（如二分查找、绝对值）中可能导致意外？ | ☐ 待解答 |
| 3 | `_BitInt` 和定宽类型（uint32_t）的区别是什么？有了定宽类型为什么还需要 `_BitInt`？ | ☐ 待解答 |

---

## ✅ 自检

- [ ] 能解释无符号整数的二进制表示公式，能用 _WIDTH 和 _MAX 宏描述类型
- [ ] 能使用位运算符（\| & ^ ~）进行标志位操作，理解位集合视角
- [ ] 能用移位替代 2 的幂乘除，知道移位边界（不能 >= 精度）
- [ ] 理解补码表示，能计算 ~A+1=-A，知道有符号溢出是 UB
- [ ] 能根据精度需求选择定宽类型或 _BitInt，知道 DBL_MIN 不是最小值
