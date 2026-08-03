/* upc.c - 计算通用产品代码的校验位 
 *
 * 1. 奇数位数字相加之和再乘以 $3$
 * 2. 偶数位数字相加
 * 3. 步骤1的结果减步骤2的结果的差再减去 $1$
 * 4. 用 $9$ 减去步骤3的结果除以 $10$ 取余数
**/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <UPC CODE>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    char const * const upc = argv[1];

    if (strlen(upc) != 12) {
        fprintf(stderr, "Please enter the correct UPC code.\n");
        return EXIT_FAILURE;
    }

    long odd = 0;
    long even = 0;

    // 奇数位相加
    for (size_t i = 0, stop = strlen(upc) - 1; i <= stop; i += 2) {
        odd += upc[i] - '0';
    }
    // 偶数位相加
    for (size_t i = 1, stop = strlen(upc) - 1; i < stop; i += 2) {
        even += upc[i] - '0';
    }

    long check = 9 - ((3 * odd) + even - 1) % 10;

    if (check == upc[strlen(upc) - 1] - '0') {
        printf("check digit is %ld. Check SUCCESS\n", check);
    } else {
        printf("Check digit must be %d. But got %ld\n", upc[strlen(upc) - 1] - '0', check);
    }

    return EXIT_SUCCESS;

}


