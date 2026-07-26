/* menu.c - 简易菜单 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {
    int menu = {0};
    do {
        printf("1. 打招呼\n");
        printf("2. 报时\n");
        printf("3. 退出\n");
        printf("请选择：");
        scanf("%d", &menu);
        switch (menu) {
            case 1:
                printf("hello~~~\n");
                break;
            case 2: 
            {
                time_t t = time(nullptr);
                struct tm tp = {};
                localtime_r(&t, &tp);
                char buffer[256];
                strftime(buffer, 256, "%Y-%m-%d %H:%M:%S", &tp);
                printf("当前时间是: %s\n", buffer);
                break;
            }         
            default:
                break;
        }

    } while(menu != 3);

    return EXIT_SUCCESS;
}

