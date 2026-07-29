/* semantic_types.c — 语义类型示例 */
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

int main(void) {
    int arr[] = {1, 2, 3, 4, 5};

    size_t len = sizeof(arr) / sizeof(arr[0]);
    for (size_t i = 0; i < len; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    ptrdiff_t diff = &arr[4] - &arr[0];
    printf("&arr[4] - &arr[0] = %td\n", diff);

    uint32_t ip = 0xC0A80001;
    printf("IP: %u.%u.%u.%u\n",
           ip >> 24, (ip >> 16) & 0xFF,
           (ip >> 8) & 0xFF, ip & 0xFF);
}
