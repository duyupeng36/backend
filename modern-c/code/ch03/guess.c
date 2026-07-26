/* guess.c - 猜数字 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    // 设置随机数种子
    srand(time(nullptr));
    int target = rand() % 100 + 1;
    int guess = 0;
    size_t count = 0;
    bool flag = false;

    printf("请猜猜现在的数字是多少，你有 7 次机会\n");
    do {
        printf("请输入你猜测的数: ");
        scanf("%d%*c", &guess);
        if (guess > target) {
            printf("\b猜大了！！剩余 %zu 次猜测机会！！", 7 - count - 1);
        } else if(guess < target) {
            printf("\b猜小了！！剩余 %zu 次猜测几乎！！", 7 - count - 1);
        } else {
            printf("恭喜猜中了！！剩余 %zu 次猜测机会！！", 7 - count - 1);
            flag = true;
            break;
        }
        ++count;
        puts("");
    } while (count < 7);
    if (!flag) {
        printf("很遗憾，你已使用完所有猜测机会！！正确值是 %d\n", target);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
