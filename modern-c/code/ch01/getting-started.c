#include <stdio.h>
#include <stdlib.h>

int main(int argc, [[maybe_unused]]char* argv[argc + 1]) {

    // ⬇ 这是声明语句: A[5] 表示长度为 5 的数组，前面的 double 表示数组的类型
    double A[5] = {
        [0] = 9.0,      // ⬅ [0] = 9.0 是 C99 标准引入的 **指定初始化**
        [1] = 2.9,
        [4] = 3.E+25,
        [3] = .00007,
        // [2] = 0.0   // ⬅ [2] 号元素没有在初始化列表中，编译器默认初始化为 0.0
    };                  // 分号表示一条语句的结束

    // 程序核心做的事情
    for (size_t i = 0; i < 5; ++i) {
        printf("element %zu is %g, \tits square is %g\n", // ⬅ 第一个参数
               i, 					// ⬅ 替换 %zu
               A[i], 				// ⬅ 替换第一个 %g
               A[i]*A[i]);			// ⬅ 替换第二个 %g  
    }

    return EXIT_SUCCESS;  // EXIT_SUCCESS 是 <stdlib.h> 头文件中预定义的标识符
}

/*
 * 预处理指令：#include
 * 关键字: int char double for return
 * 标识符: main(函数) size_t(类型) EXIT_SUCCESS(常量) argc argv A i(数据对象)
 * 标点：[] [[]] () {} <> ; , (块注释)
 * 运算符：= < ++ *
 * 字面量：1 5 9.0 2.9 3.E+25 .00007  "element %zu is %g, \tits square is %g\n",
 * 注释: //(行注释) 和 (块注释) 
 *
**/

