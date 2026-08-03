#include <stdio.h>
#include <stdlib.h>
int main(void) {

    
    printf("10:00 过 3 小时后是 %02d:00\n", (10 + 3) % 24);
    printf("20:00 过 8 小时后是 %02d:00\n", (20 + 8) % 24);
    return EXIT_SUCCESS;

}
