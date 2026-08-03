#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    size_t number = 0;
    printf("请输入一个正整数：");
    scanf("%zu", &number);

    if (number == 0) {
        fprintf(stderr, "请输入正整数\n");
        return EXIT_FAILURE;
    }

    bool flag = number < 2 ? false : true;
    // 对于每个 number
    for (size_t factor = 3; factor * factor <= number; factor = factor + 2) {
        if (!(number % factor)) {
            flag = false;
            break;
        }
    }
    printf("The number %zu is %s\n", number, flag ? "prime number." : "not prime number.");
    return EXIT_SUCCESS;
}
