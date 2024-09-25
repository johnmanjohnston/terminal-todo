#include "group_component.h"
#include "../color.h"
#include "../component.h"

// rendering
void render_group_component(group_component g) {
    if (g.cdata.is_focused)
        set_text_color(hex_c(0xe5e5e5));
    else
        set_text_color(hex_c(0x8f8f8f));

    render_textbox(g.textbox);
    render_panel(g.panel, 1);

    set_text_color(foreground_c());
}
void erase_group_component(group_component g) {
    erase_textbox(g.textbox);
    erase_panel(g.panel);
}

// focus
void group_component_blur(void *component) {}
void group_component_focus(void *component) {}

// misc.
// WARN: INITIALIZATION SHOULD BE DONE ***AFTER*** POSITIONING COMPONENT
void initialize_group_component(group_component *g) {
    g->panel.cdata.component_typecode = 0x2;
    g->textbox.cdata.component_typecode = 0x3;
    // panel dimensions should be assigned

    g->panel.cdata.x = g->cdata.x;
    g->panel.cdata.y = g->cdata.y;

    g->textbox.cdata.x = g->cdata.x + 1;
    g->textbox.cdata.y = g->cdata.y + 1;

    g->textbox.cdata.full_component = (void *)&g->textbox;
    initialize_component(&g->textbox, 0x3);

    // initialize_textbox(&g->textbox);
}
void release_group_component_resources(group_component *g) {
    release_textbox_resources(&g->textbox);
}
void handle_group_component_key_input(void *component, char key) {
    group_component g = *(group_component *)(component);
    handle_textbox_key_input((void *)&g.textbox, key);
}
