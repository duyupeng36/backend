#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {    
        fprintf(stderr, "Usage: %s <fahrenheit>\n", argv[0]);
        return EXIT_FAILURE;
    }
    double fahrenheit = strtod(argv[1], nullptr);
    
    double celsius = 5.0 / 9.0 * (fahrenheit - 32.0);
    printf("%.4g °F= %.4g °C\n", fahrenheit, celsius);
    return EXIT_SUCCESS;
}
