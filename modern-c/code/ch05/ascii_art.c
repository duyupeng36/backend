#include <stdio.h>
#include <stdlib.h>

int main(void) {

    
    for (size_t i = 1; i <= 5; ++i) {

        for (size_t j = 0; j < 2 * i - 1; ++j) {
            j == 0 ? printf("%*c", (int)(5 - i + 1), '*') : printf("%c", '*');
        }
        puts("");
    }

    return EXIT_SUCCESS;
}

