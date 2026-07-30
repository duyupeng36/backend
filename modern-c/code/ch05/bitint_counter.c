#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
    unsigned _BitInt(3) counter = 0wbu;
   
    for (size_t i = 0; i < 10; ++i) {
        ++counter;
        printf("%w32u ", (uint32_t)(counter));
    }
    puts("");

    return EXIT_SUCCESS;
}
