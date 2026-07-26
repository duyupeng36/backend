/* validate.c - 校验用户输入的数据 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int number = {0};
    do {
        printf("输入 1 ~ 100 之间的正整数");
        scanf("%d", &number);

    } while (!(number >= 1 && number <= 100));
    printf("number = %d\n", number);
    return EXIT_SUCCESS;
}
