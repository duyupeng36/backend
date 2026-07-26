/* primes.c - 统计 N 以内的素数个数 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <N>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int number = (int)strtol(argv[1], NULL, 0);

    if (number <= 0) {
        fprintf(stderr, "number must be greater than zero.");
        return EXIT_FAILURE;
    }

    int count = number >= 2 ? 1 : 0; // 统计 N 以内素数的个数
    
    // 遍历目标数: 从 3 开始，素数只有可能是奇数
    for (int target = 3; target <= number; target += 2) {

        // number 如果是 5 的倍数也不用判断
        if (target != 5 && !(target % 5)) {
            continue;
        }

        bool prime = true;
        // 判断 target 的因子是否只有 1 和 target 两个
        // 奇数的因子不可能为 2 也不可能为偶数
        for (int factor = 3; factor * factor <= target; factor += 2) {
            // 找到一个额外因子；结束判断
            if (!(target % factor)) {
                prime = false;
                break;
            }
        }
        // target 是素数：计数 + 1
        if (prime) {
            ++count;
        }
    }


    printf("less than %d has %d prime number!\n", number, count);
    return EXIT_SUCCESS;

}

