#pragma once
#include "base.h"

typedef struct {
    struct component_data cdata;
    int width;
    int height;
} panel;

void render_panel(panel p);
