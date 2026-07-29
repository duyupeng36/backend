/* basic_types.c — 查看当前平台的基本类型宽度 */
#include <stdio.h>
#include <stdint.h>

int main(void) {
    printf("=== 当前平台数据模型 ===\n");
    printf("char      : %2zu 字节\n", sizeof(char));
    printf("short     : %2zu 字节\n", sizeof(short));
    printf("int       : %2zu 字节\n", sizeof(int));
    printf("long      : %2zu 字节\n", sizeof(long));
    printf("long long : %2zu 字节\n", sizeof(long long));
    printf("指针      : %2zu 字节\n", sizeof(void*));
    // 根据 int=4, long=8, 指针=8 → LP64 模型
}
