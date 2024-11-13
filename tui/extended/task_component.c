#include "task_component.h"
#include "../color.h"
#include "../component.h"

void render_task_component(task_component t) {
    if (t.cdata.is_focused)
        set_text_color(hex_c(0xff0000));
    else
        set_text_color(hex_c(0x8f8f8f));

    t.panel.cdata.x = t.cdata.x;
    t.panel.cdata.y = t.cdata.y;
    t.textbox.cdata.x = t.cdata.x + 1;
    t.textbox.cdata.y = t.cdata.y + 1;

    render_panel(t.panel, 0);
    render_textbox(
        t.textbox); // TODO: instead of using render_textbox(), write another
                    // function to render a textbox which handles line wrapping

    set_text_color(foreground_c());
}

void erase_task_component(task_component t) {
    t.panel.cdata.x = t.cdata.x;
    t.panel.cdata.y = t.cdata.y;
    t.textbox.cdata.x = t.cdata.x + 1;
    t.textbox.cdata.y = t.cdata.y + 1;

    erase_panel(t.panel);
    erase_textbox(t.textbox);
}

void task_component_focus(void *component) {}
void task_component_blur(void *component) {}

void initialize_task_component(task_component *t) {

    t->panel.cdata.component_typecode = 0x2;
    t->textbox.cdata.component_typecode = 0x3;
    // panel dimensions should be assigned
    t->panel.cdata.x = t->cdata.x;
    t->panel.cdata.y = t->cdata.y;

    t->textbox.cdata.x = t->cdata.x + 1;
    t->textbox.cdata.y = t->cdata.y + 1;

    t->textbox.cdata.full_component = (void *)&t->textbox;
    initialize_component(&t->textbox, 0x3);
    t->cdata.is_focused = 0;
}

void handle_task_component_key_input(void *component, char key) {
    task_component t = *(task_component *)(component);
    handle_textbox_key_input((void *)&t.textbox, key);
}

void release_task_component_resources(task_component *t) {
    release_textbox_resources(&t->textbox);
}
