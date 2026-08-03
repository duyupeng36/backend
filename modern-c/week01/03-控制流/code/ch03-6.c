#include <stdio.h>

int main(void) {

    int count = 3;

    switch (count) {
        default: puts("++++ ..... +++"); [[fallthrough]];
        case 4:  puts("++++"); [[fallthrough]];
        case 3:  puts("+++"); [[fallthrough]];
        case 2:  puts("++"); [[fallthrough]];
        case 1:  puts("+"); [[fallthrough]];
        case 0:  // 空
    }

    return 0;
}
