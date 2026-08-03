#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return EXIT_FAILURE;
    }

    size_t number = strtoull(argv[1], nullptr, 0);

    size_t count = 1;

    // 从 1 开始遍历到 number
    for (size_t target = 3; target <= number; target = target + 2) {
        bool flag = true;
        // 对于每个 number
        for (size_t factor = 3;  factor * factor <= target; factor = factor + 2) {
            if (!(target % factor)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ++count;
        }
    }

    printf("There are a total of %zu prime numbers in %zu\n", count, number);
    return EXIT_SUCCESS;
}
