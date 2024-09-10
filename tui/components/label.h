#pragma once
#include "base.h"

typedef struct {
    struct component_data cdata;
    char *text;
} label;

void erase_label(label l);
void render_label(label l);
