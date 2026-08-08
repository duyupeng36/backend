# main 函数

> week02 · C 语言全貌 · 知识点 48

> 状态：☑ 已完成

---

## 速览

**main 函数**是程序的入口点，由 C 标准强制规定原型。有两种标准形式：`int main(void)` 和 `int main(int argc, char* argv[])`。main 函数的返回值使用 `EXIT_SUCCESS` 或 `EXIT_FAILURE`。命令行参数通过 argc（个数）和 argv（字符串数组）传递

---

## 是什么

`main` 函数是程序的入口点，由 C 标准强制规定原型，但由程序员实现。它是运行时系统和应用程序之间的枢纽，必须遵守特殊规则

---

## 详细解释

`main` 函数是所有 C 程序的起点。当你运行一个程序时，操作系统会调用 `main` 函数。`main` 函数的特殊之处在于：

+ 它的原型由 C 标准强制规定，程序员不能随意修改
+ 它是运行时系统和应用程序之间的桥梁
+ 它有一些特殊的规则，其他函数没有

### main 函数的原型

C 标准规定了两种 `main` 函数的原型；依据程序执行是否需要命令行参数进行分类。程序员必须实现其中一种

```c
// 形式1：无命令行参数
int main(void);
// 形式2：带命令行参数
int main(int argc, char* argv[argc+1]);
```

当我们在终端运行程序时，可以传递参。这些参数会通过 `main` 函数的参数传递给程序。例如

```c
./program arg1 arg2 arg3
```

在 `main` 函数中，我们可以通过 `main` 函数的参数 `argc` 和 `argv` 访问这些参数

+ `argc` 是参数的个数。注意：包含程序名在内
+ `argv` 是一个 `char*` 数组，元素都指向命令行参数

```c
int main(int argc, char* argv[argc+1]) {
    // argc = 参数个数（包括程序名）
    // argv[0] = "./program"（程序名）
    // argv[1] = "arg1"（第一个参数）
    // argv[2] = "arg2"（第二个参数）
    // argv[3] = "arg3"（第三个参数）
    // argv[4] = nullptr（结束标记）
}
```

> [!WARNING]
>
> 请注意：所有命令行参数都以字符串形式传递。`argv` 长度等于 `argc + 1`，其中最后一个元素一定是 `nullptr` 作为结束标记 

操作系统还可以定义自己的 `main` 函数原型。如果想要编写可移植的代码，那么非 C 标准定义的 `main` 函数原型一定不要使用。下面是两种比较常见的变体

+ 在一些嵌入式平台上，如不期望 `main` 返回运行时系统，那么返回类型可以是 `void`

+ 在许多平台上，第三个参数可以访问环境变量

### main 函数的返回值

C 程序是从 `main` 函数开始执行的，如果 `main` 函数返回，就意味着 C 程序执行结束。`main` 一般会返回一个 `int` 类型 `EXIT_SUCCESS` 或 `EXIT_FAILURE` 用于向运行时系统指示执行是否成功。某些编译器并不要求显示的写出 `main` 函数的返回值；因为编译器会自动为 `main` 函数补充 `return EXIT_SUCCESS`。注意：**我们应该显示指定 `main` 函数的返回值，不要依赖编译器**。

```c
int main(void) {
    // 到达末尾等价于 return EXIT_SUCCESS
    return EXIT_SUCCESS;  // 成功
    // 或者
    return EXIT_FAILURE;  // 失败
}
```

> [!TIP]
>
> 请使用 `EXIT_SUCCESS` 和 `EXIT_FAILURE` 作为 `main` 的返回值。这两个值是唯二在所有平台上都能正常工作的返回值。

### 程序终止

函数 `exit` 来自于 `<stdlib.h>` 头文件，它用来终止程序，效果与从 `main` 函数返回相同

```c
#include <stdlib.h>
[[noreturn]] void exit(int status);
```

调用 `exit(s)` 等价于在 `main` 中执行 `return s`。注意，`[[noreturn]]` 是 C23 引入的标准属性，它告诉编译器该函数永远不会返回到调用者；这对于优化和静态分析很有帮助


---

## 代码示例

`main-demo.c` — 演示 main 函数的特性：参数解析、返回值、字符串处理

```c
/* main-demo.c - 演示 main 函数的特性 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 辅助函数：将字符串转换为大写
void to_upper(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}

// 辅助函数：打印使用说明
void print_usage(const char *program_name) {
    fprintf(stderr, "用法: %s <选项> <参数>\n", program_name);
    fprintf(stderr, "选项:\n");
    fprintf(stderr, "  -u <字符串>  转换为大写\n");
    fprintf(stderr, "  -r <字符串>  反转字符串\n");
    fprintf(stderr, "  -l <字符串>  计算长度\n");
    fprintf(stderr, "  -h           显示帮助\n");
}

int main(int argc, char *argv[argc + 1]) {
    // 检查参数个数
    if (argc < 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }
    
    // 处理选项
    char const* option = argv[1];
    
    if (strcmp(option, "-h") == 0) {
        // 显示帮助
        print_usage(argv[0]);
        return EXIT_SUCCESS;
    }
    
    if (argc < 3) {
        fprintf(stderr, "错误: 选项 %s 需要参数\n", option);
        return EXIT_FAILURE;
    }
    
    char const* input = argv[2];
    
    if (strcmp(option, "-u") == 0) {
        // 转换为大写
        char buffer[256];
        strncpy(buffer, input, sizeof(buffer) - 1);
        buffer[sizeof(buffer) - 1] = '\0';
        to_upper(buffer);
        printf("大写: %s\n", buffer);
    } 
    else if (strcmp(option, "-r") == 0) {
        // 反转字符串
        int len = strlen(input);
        printf("反转: ");
        for (int i = len - 1; i >= 0; i--) {
            putchar(input[i]);
        }
        putchar('\n');
    }
    else if (strcmp(option, "-l") == 0) {
        // 计算长度
        printf("长度: %zu\n", strlen(input));
    }
    else {
        fprintf(stderr, "未知选项: %s\n", option);
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}
```

**演示的知识点**：

| 知识点 | 代码体现 |
|--------|----------|
| main 函数原型 | `int main(int argc, char *argv[argc + 1])` |
| argc 参数 | 检查 `argc < 2` 和 `argc < 3` |
| argv 参数 | `argv[0]` 是程序名，`argv[1]` 是选项，`argv[2]` 是参数 |
| 返回值 | `return EXIT_SUCCESS` 和 `return EXIT_FAILURE` |
| 字符串比较 | `strcmp(option, "-h")` |
| 字符串长度 | `strlen(input)` |
