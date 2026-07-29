#include <stdio.h>
#include <stdlib.h>
int main(void) {
    
    printf("-1 < 0 : %d(true, 无害，相同符号)\n", -1 < 0);
    printf("-1L < 0 : %d(true, 无害，相同符号)\n", -1L < 0 );
    printf("-1U < 0U : %d(false, 无害，相同符号)\n", -1U < 0U );
    printf("-1 < 0U : %d(false, 危险，不同符号)\n", -1 < 0U );
    printf("-1U < 0 : %d(false, 危险，不同符号)\n", -1U < 0 );
    printf("-1L < 0U : %d(具体实现, 危险, 不同符号)\n", -1L < 0U );
    printf("-1LL < 0UL : %d(具体实现, 危险, 不同符号)\n", -1LL < 0UL);

    return EXIT_SUCCESS;
}


