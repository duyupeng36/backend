/* leap.c - 判断一个年份是否是闰年 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <year>\n", argv[0]);
        return EXIT_FAILURE;
    }

    long year = strtol(argv[1], nullptr, 0);
    
    if (!(year % 400)) {
        printf("%ld is leap year.\n", year);
    } else {
        if (!(year % 4) && (year % 100)) {
            printf("%ld is leap year.\n", year);
        } else {
            printf("%ld is not leap year.\n", year);
        }
    }
}
