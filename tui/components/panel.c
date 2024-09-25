#include "panel.h"
#include "../core.h"
#include "../utility.h"
#include <stdio.h>

void render_panel(panel p, int should_draw_horizontal_line) {
    // draw top line and top corners
    set_cursor_position(p.cdata.x, p.cdata.y);
    for (int i = 0; i < p.width; i++) {
        if (i == 0)
            printf("\u250C");
        else if (i == p.width - 1)
            printf("\u2510");
        else
            printf("\u2500");
    }

    // draw side lines
    for (int i = 0; i < p.height; i++) {
        set_cursor_position(p.cdata.x, p.cdata.y + i + 1);
        printf("\u2502");

        set_cursor_position(p.cdata.x + p.width - 1, p.cdata.y + i + 1);
        printf("\u2502");
    }

    // draw bottom line and bottom corners
    set_cursor_position(p.cdata.x, p.cdata.y + p.height + 1);
    for (int i = 0; i < p.width; i++) {
        if (i == 0)
            printf("\u2514");
        else if (i == p.width - 1)
            printf("\u2518");
        else
            printf("\u2500");
    }

    if (should_draw_horizontal_line == 1)
        draw_horizontal_line(p.cdata.x, p.cdata.y + 2, p.width, NULL, NULL,
                             NULL);
}

void erase_panel(panel p) {
    // erase top line and top corners
    set_cursor_position(p.cdata.x, p.cdata.y);
    for (int i = 0; i < p.width; i++) {
        printf(" ");
    }

    // erase side lines
    for (int i = 0; i < p.height; i++) {
        set_cursor_position(p.cdata.x, p.cdata.y + i + 1);
        printf(" ");

        set_cursor_position(p.cdata.x + p.width - 1, p.cdata.y + i + 1);
        printf(" ");
    }

    // erase bottom line and bottom corners
    set_cursor_position(p.cdata.x, p.cdata.y + p.height + 1);
    for (int i = 0; i < p.width; i++) {
        printf(" ");
    }
}
