/* guess-number.c - 猜数字 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
    // 设置随机数种子
    srand(time(NULL));
    
    // 1 ~ 100 内的随机数
    int target = rand() % 100 + 1;

    int guess = 0;
    size_t count = 0;
    printf("我想了一个 1 ~ 100 的数字，请猜测: ");
    while (true) {
        scanf("%d", &guess);
        ++count;
        if (guess < target) {
            printf("小了！再猜: ");
        } else if (guess > target) {
            printf("大了！再猜: ");
        } else {
            printf("恭喜你，猜对了！共猜了 %zu 次", count);
            break;
        }
    }

    return EXIT_SUCCESS;
}
