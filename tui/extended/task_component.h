#pragma once
#include "../components/panel.h"
#include "../components/textbox.h"

typedef struct {
    struct component_data cdata;
    textbox textbox;
    panel panel;
} task_component;

void render_task_component(task_component t);
void erase_task_component(task_component t);

void task_component_focus(void *component);
void task_component_blur(void *component);

void initialize_task_component(task_component *t);
void handle_task_component_key_input(void *component, char key);
void release_task_component_resources(task_component *t);
