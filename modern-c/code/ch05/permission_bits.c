
#include <stdio.h>
#include <stdlib.h>

enum permission { EXECUTE = 0x1U, WRITE = 0x2U, READ = 0x4U };



int main(int argc, char* argv[argc + 1]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <permission>\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned permission = (unsigned) strtoul(argv[1], nullptr, 0);

    if (permission & EXECUTE) {
        printf("EXECUTE\n");
    }
    
    if (permission & WRITE) {
        printf("WRITE\n");
    }

    if (permission & READ) {
        printf("READ\n");
    }

    return EXIT_SUCCESS;
}

