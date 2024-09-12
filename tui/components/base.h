#pragma once

struct component_data {
    int x;
    int y;
    int component_typecode;
    void *full_component;

    int focusable;   // bool
    int takes_input; // bool
    void (*handle_key_input)(void *component, char key);
};

void position_component(struct component_data *c, int x, int y);
