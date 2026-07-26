/* primes.c - 统计 N 以内的素数个数 */
#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

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

    int count = number > 3 ? 2 : number > 2 ? 1 : 0;
    
    // 遍历目标数: 孪生素数表 5 7 11 13 17 19 23
    for (int target = 5, step = 2; target <= number; target += step, step = 6 - step) {

        // number 如果是 5 的倍数也不用判断
        if ( target != 5 && !(target % 5)) {
            continue;
        }

        bool prime = true;
        // 判断 target 的因子是否只有 1 和 target 两个
        // 奇数的因子不可能为 2 也不可能为偶数
        for (int factor = 3, stop = (int)sqrt(target) + 1; factor < stop; factor += 2) {
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

