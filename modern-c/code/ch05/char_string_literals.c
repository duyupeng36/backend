/* char_string_literals.c — 字符和字符串字面量 */
#include <stdio.h>

int main(void) {
    // 字符字面量是 int，不是 char
    printf("sizeof('a')  = %zu (int!)\n", sizeof('a'));
    printf("sizeof(char) = %zu\n", sizeof(char));

    // 'a' 和 "a" 完全不同
    printf("'a'  = %d (int)\n", 'a');
    printf("\"a\"  = %zu 字节 (char[2]: 'a' + '\\0')\n", sizeof("a"));

    // '0' 和 '\\0' 截然不同
    printf("'0'  = %d\n", '0');    // ASCII 8
    printf("'\\0' = %d\n", '\0');  // 0

    // 字符串自动拼接
    printf("这三行会被"
           "编译器自动"
           "合并为一行\n");
}
