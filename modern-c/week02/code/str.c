
#include <string.h>
#include <stdio.h>
int main(int argc, char* argv[argc+1]) {
    size_t const len = strlen(argv[0]);  // 计算长度
    char name[len+1] = { };              // 初始化 VLA
    memcpy(name, argv[0], len);          // 复制数组
    if (!strcmp(name, argv[0])) {         // 比较字符串
        printf("program name \"%s\" successfully copied\n", name);
    } else {
        printf("copying %s leads to different string %s\n", argv[0], name);
    }
}

