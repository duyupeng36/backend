/* wrap_around.c - 验证回绕 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {

     printf("SIZE_MAX + 1 == 0 : %s\n", SIZE_MAX + 1 == 0 ? "true" : "false");
     printf("       0 - 1 == SIZE_MAX : %s\n", 0 - 1 == SIZE_MAX ? "true" : "false" );
    return EXIT_SUCCESS;
}
