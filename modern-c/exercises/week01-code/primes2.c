/* primes2.c - 输出 N 以内的所有素数以及素数的个数 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return EXIT_FAILURE;
    }

    size_t number = strtoull(argv[1], nullptr, 0);

    size_t count = 3;  // 2 3 5 是已知的素数
    printf("%d %d %d ", 2, 3, 5);
    // 从 1 开始遍历到 number
    for (size_t target = 7, step = 4; target <= number; target = target + step, step = 6 - step) {
        // 对于大于 5 的数，5 的倍数一定不是素数
        if (!(target % 5)) {
            continue;
        }
        bool flag = true;
        // 对于每个 number
        for (size_t factor = 3;  factor * factor <= target; factor = factor + 2) {
            if (!(target % factor)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            if (!(count % 10)) {
                puts("");
            }
            printf("%zu ", target);
            ++count;
        }
    }

    printf("\nThere are a total of %zu prime numbers in %zu\n", count, number);
    return EXIT_SUCCESS;
}
