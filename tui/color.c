#include "color.h"
#include "core.h"
#include <stdio.h>

color hex_c(int col) {
    color retval;
    retval.r = (col >> 16) & 0xFF;
    retval.g = (col >> 8) & 0xFF;
    retval.b = col & 0xFF;
    return retval;
}

color rgb_c(unsigned int r, unsigned int g, unsigned int b) {
    color retval;
    retval.r = r;
    retval.g = g;
    retval.b = b;
    return retval;
}

void ansi_reset() { printf("\033[m"); }

void set_text_color(color c) { printf("\033[38;2;%d;%d;%dm", c.r, c.g, c.b); }

void fill_with_color(color c) {
    printf("\033[48;2;%d;%d;%dm", c.r, c.g, c.b);

    for (int y = 0; y < get_terminal_height() + 1; y++) {
        set_cursor_position(0, y);
        for (int x = 0; x < get_terminal_width(); x++) {
            printf(" ");
        }
    }
}

// theme
// yoink gruvbox colors: https://github.com/morhetz/gruvbox
color background_c() { return hex_c(0x282828); }
color foreground_c() { return hex_c(0xf9f5d7); }
color red_c() { return hex_c(0xfb4934); }
