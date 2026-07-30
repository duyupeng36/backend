# Modern C 笔记：ch05-基本值与数据（下）——二进制表示

> 章节：第 5 章 · Basic Values and Data（基本值与数据）  
> 日期：2026-07-26  
> 状态：☑ 已完成（第二部分 10-18）

---

## 📋 速览

无符号整数是模 2^p 的环，位运算符（\|、&、^、~）提供了集合操作视角，移位运算（<<、>>）连接了数值和位集合。有符号整数使用补码：正值表示与无符号一致，~A+1 = -A，溢出是 UB。定宽类型（uint32_t 等）提供精确宽度，_BitInt（C23）支持任意位数。浮点数据由符号-指数-尾数三部分组成，精度有限，运算不满足结合律/交换律/分配律——大数吞小数，永远不直接比较相等。

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
