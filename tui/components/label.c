#include "label.h"
#include "../core.h"
#include <stdio.h>
#include <string.h>

void render_label(label l) {
    set_cursor_position(l.cdata.x, l.cdata.y);
    printf("%s", l.text);
}

void erase_label(label l) {
    set_cursor_position(l.cdata.x, l.cdata.y);

    for (int i = 0; i < strlen(l.text); i++) {
        printf(" ");
    }
}
