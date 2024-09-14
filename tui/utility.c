#include "utility.h"
#include "core.h"
#include <stdio.h>

void draw_horizontal_line(unsigned int x, unsigned int y,
                          unsigned int char_count, char *c, char *start_char,
                          char *end_char) {
    if (c == NULL) {
        c = "\u2500";
    }

    if (start_char == NULL) {
        start_char = "\u251c";
    }

    if (end_char == NULL) {
        end_char = "\u2524";
    }

    set_cursor_position(x, y);

    for (int i = 0; i < char_count; i++) {
        if (i == 0)
            printf("%s", start_char);
        else if (i == char_count - 1)
            printf("%s", end_char);
        else
            printf("%s", c);
    }
}
