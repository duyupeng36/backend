#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {

        fprintf(stderr, "Usage: %s <year>\n", argv[0]);
        return EXIT_FAILURE;;
    }

    long year = strtol(argv[1], NULL, 0);

    printf("%ld is %s\n", year, !(year % 400) || (!(year % 4) && (year % 100)) ? "leap year": "not leap year");
    return EXIT_SUCCESS;
}
