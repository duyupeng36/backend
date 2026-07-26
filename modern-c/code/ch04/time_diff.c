#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int hours[2] = {};
    int minutes[2] = {};
    int seconds[2] = {};

    for (int i = 0; i < 2; ++i) {
        printf("输入时间(时:分:秒): ");
        scanf("%d:%d:%d", &hours[i], &minutes[i], &seconds[i]);
    }

    int diff = (60 * 60 * hours[0] + 60 * minutes[0] + seconds[0]) - (60 * 60 * hours[1] + 60 * minutes[1] + seconds[1]);
    printf("相差 %d 秒\n", diff);

    return EXIT_SUCCESS;
}
