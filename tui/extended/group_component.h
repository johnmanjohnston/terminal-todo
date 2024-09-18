#include "../components/panel.h"
#include "../components/textbox.h"

typedef struct {
    struct component_data cdata;

    textbox textbox;
    panel panel;
} group_component;

// rendering
void render_group_component(group_component g);
void erase_group_component(group_component g);

// focus
void group_component_blur(void *component);
void group_component_focus(void *component);

// misc.
void initialize_group_component(group_component *g);
void release_group_component_resources(group_component *g);
void handle_group_component_key_input(void *component, char key);
