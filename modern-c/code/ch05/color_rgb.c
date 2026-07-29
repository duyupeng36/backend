/* color_rgb.c */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define COLOR 0xFF9933

int main(void) {

    uint32_t color = COLOR;

    uint32_t red = (color & (0xFF << 16)) >> 16;
    uint32_t green = (color & (0xFF << 8)) >> 8;
    uint32_t blue = color & 0xFF;

    printf("RED: %#x GREEN: %#x BLUE: %#x\n", red, green, blue);
    return EXIT_SUCCESS;
}

