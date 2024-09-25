#include "group_component.h"
#include "../color.h"
#include "../component.h"
#include "stdlib.h"
#include "task_component.h"

#include "../core.h"
#include "stdio.h"

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
    //

    g->task_count = 0;
    g->task_components = NULL;
}
void release_group_component_resources(group_component *g) {
    release_textbox_resources(&g->textbox);

    if (g->task_components > 0)
        free(g->task_components);

    g->task_components = NULL;
}
void handle_group_component_key_input(void *component, char key) {
    group_component g = *(group_component *)(component);
    handle_textbox_key_input((void *)&g.textbox, key);
}

// for functions where you're basically reimplementing vectors, just yoink the
// the focus_manager code
void add_task_component_to_group(group_component *g, task_component *t) {
    // handle memory changes when adding task to group
    g->task_count++;
    g->task_components = (task_component **)realloc(
        g->task_components, sizeof(task_component *) * g->task_count);
    g->task_components[g->task_count - 1] = t;

    set_cursor_position(21, 20);
    /*
    if (g->task_components == NULL) {
        printf("g->task_components is NULL");
    } else {
        printf("g->task_components reallocated");
    }
    */

    // handle visual changes when adding task to group
    // TODO: you will need to change this because of task's textboxes wrapping
    // around and stuff
    t->cdata.x = g->cdata.x + 1;
    t->cdata.y = g->cdata.y + 1 + 2;
}
void add_task_component_to_group_with_index(group_component *g,
                                            task_component *t,
                                            unsigned int index) {}
void remove_task_from_group(group_component *g, task_component *t) {
    // handle memory changes when removing task from group
    int index = -1;

    for (int i = 0; i < g->task_count; i++) {
        if (&g->task_components[i]->cdata == &t->cdata) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index + 1; i < g->task_count; i++) {
            g->task_components[i - 1] = g->task_components[i];
        }

        // apparently you should not use the updated count of task_components
        // otherwise you get a segfault???
        // TODO: make sure this is memory safe
        g->task_components = (task_component **)(realloc(
            g->task_components, sizeof(task_component *) * g->task_count));

        g->task_count--;
    }

    // handle visual changes when removing task from group
    expurgate(t->cdata.full_component);
}
