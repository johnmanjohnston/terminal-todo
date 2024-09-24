#pragma once

struct component_data {
    int x;
    int y;
    int component_typecode;
    void *full_component;

    int focusable;   // bool
    int takes_input; // bool
    int is_focused;  // bool

    void (*handle_key_input)(void *component, char key);
    void (*on_focus)(void *component);
    void (*on_blur)(void *component);
};

void position_component(struct component_data *c, int x, int y);

/* Functions to implement for a new component:
// rendering
void render_COMPONENT_NAME_component(COMPONENT_TYPE);
void erase_COMPONENT_NAME_component(COMPONENT_TYPE);

// focus (if applicable)
void COMPONENT_NAME_blur(void *component);
void COMPONENT_NAME_focus(void *component);

// misc.
void initialize_COMPONENT_NAME_component(COMPONENT_TYPE);
void release_COMPONENT_NAME_resources(COMPONENT_TYPE); // if applicable
void handle_COMPONENT_NAME_key_input(void *component, char key);
*/
