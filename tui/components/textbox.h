#pragma once
#include "base.h"

typedef struct {
    struct component_data cdata;
    char *text;
} textbox;

void textbox_blur(void *component);
void textbox_focus(void *component);

void initialize_textbox(textbox *t);
void release_textbox_resources(textbox *t);
void handle_textbox_key_input(void *component, char key);
void erase_textbox(textbox t);
void render_textbox(textbox t);
