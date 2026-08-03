/* grade.c - 成绩等级判定 */
#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int grade = 0;
    printf("请输入成绩: ");
    scanf("%d", &grade);

    switch (grade / 10) {
        case 10: case 9: printf("A\n"); break;
        case 8: printf("B\n"); break;
        case 7: printf("C\n"); break;
        case 6: printf("D\n"); break;
        default: printf("F\n");
    
    }

    return EXIT_SUCCESS;
}

