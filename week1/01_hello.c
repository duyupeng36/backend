// week1/01_hello.c —— 你的第一个 C 程序
// 对比 Python: print("Hello, 潇洒哥")

#include <stdio.h>   // 预处理器指令：把头文件 stdio.h 的内容粘贴到这里
                      // stdio.h 声明了 printf 函数

int main(void) {      // 程序入口——C 必须有 main 函数, Python 没有
    printf("Hello, 潇洒哥!\n");  // 输出字符串, \n 是换行
    return 0;         // 返回 0 表示程序正常结束（操作系统会收到这个值）
}
