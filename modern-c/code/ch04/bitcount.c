/* bitcount.c - 给定一个全为 0 或 1 的数组，统计其中 0 和 1 各有多少个 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int A[] = {1, 1, 0, 0, 1, 0, 1};
    int count[2] = {0, 0};
    for (size_t i = 0; i < sizeof(A) / sizeof(A[0]); ++i) {
        ++count[A[i] == 1];
    }
    printf("==0 : %d\n==1 : %d\n", count[0], count[1]);
    return EXIT_SUCCESS;
}

