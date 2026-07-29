/* designated_init.c  */
#include <stdio.h>
#include <stdlib.h>
int main(void) {

    int array[7] = {
        [0] = 9,
        [3] = 7,
        [6] = 3,
    };

    for (size_t i = 0; i < sizeof(array) / sizeof(array[0]); ++i) {
        printf("array[%zu] = %d\n", i, array[i]);
    }

    return EXIT_SUCCESS;
}
