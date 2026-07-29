/* data_model.c - 识别当前平台的数据模型  */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    size_t sizei = sizeof(int);
    size_t sizel = sizeof(long);
    size_t sizep = sizeof(void *);

    char *model = nullptr;

    if (sizei == 2 && sizel == 4 && sizep == 4) {
        model = "LP32";
    } else if (sizei == 4 && sizel == 4 && sizep == 4) {
        model = "ILP32";
    } else if (sizei == 4 && sizel == 4 && sizep == 8 ) {
        model = "LLP64";
    } else if (sizei == 4 && sizel == 8 && sizep == 8) {
        model = "LP64";
    }

    if (model) {
        puts(model);
    } else {
        puts("Unknow data model");
    }

    return EXIT_SUCCESS;

}

