/* guess-number2.c - 猜数字 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

constexpr size_t total_count = 7; 

int main(void) {
    // 设置随机数种子
    srand(time(NULL));
    // 1 ~ 100 内的随机数
    int target = rand() % 100 + 1;
    
    int guess = 0;
    printf("我想了一个 1 ~ 100 的数字，你有 7 次机会!");
    for (size_t i = 0; i < 7; ++i) {
        printf("\n第 %zu 次 猜测: ", i + 1);
        scanf("%d", &guess);
        if (guess < target) {
            printf("小了！");
        } else if (guess > target) {
            printf("大了!");
        } else {
            printf("恭喜你，猜对了！共猜了 %zu 次，剩余 %zu 次\n", i + 1, total_count - i - 1);
            break;
        }
    }

    return EXIT_SUCCESS;
}
