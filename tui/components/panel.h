#pragma once
#include "base.h"

typedef struct {
    struct component_data cdata;
    int width;
    int height;
} panel;

void erase_panel(panel p);
void render_panel(panel p, int should_draw_horizontal_line);
