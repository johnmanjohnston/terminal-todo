#pragma once
#include "../components/panel.h"
#include "../components/textbox.h"
#include "task_component.h"

typedef struct {
    struct component_data cdata;

    textbox textbox;
    panel panel;

    task_component **task_components;
    unsigned int task_count;
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

// component-specific
void add_task_component_to_group(group_component *g, task_component *t);
void add_task_component_to_group_with_index(group_component *g,
                                            task_component *t,
                                            unsigned int index);
void remove_task_from_group(group_component *g, task_component *t);
