#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// 函数原型
bool is_prime(size_t number);


int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return EXIT_FAILURE;
    }

    size_t number = strtoull(argv[1], nullptr, 0);

    size_t count = 3;  // 2 3 5 是已知的素数

    // 从 1 开始遍历到 number
    for (size_t target = 7, step = 4; target <= number; target = target + step, step = 6 - step) {
        // 对于大于 5 的数，5 的倍数一定不是素数
        if (!(target % 5)) {
            continue;
        }
        bool flag = is_prime(target);
        if (flag) {
            ++count;
        }
    }

    printf("There are a total of %zu prime numbers in %zu\n", count, number);
    return EXIT_SUCCESS;
}

bool is_prime(size_t number) {

    if (number < 2) {
        return false;
    }
    // 假设它是素数
    bool result = true;

    for (size_t factor = 3, stop = (size_t)sqrt(number);  factor < stop + 1; factor += 2) {
        if (!(number % factor)) {
            result = false;
            break;
        }
    }

    return result;
}
