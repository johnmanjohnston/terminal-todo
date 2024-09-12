#include "textbox.h"
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEXTBOX_BUFFER_SIZE 32

void initialize_textbox(textbox *t) {
    t->text = malloc(sizeof(char) * TEXTBOX_BUFFER_SIZE); // *sigh*
}

void handle_textbox_key_input(void *component, char key) {
    textbox *t = ((textbox *)(component));
    set_cursor_position(0, 0);

    // t->text = &key;

    strcpy(t->text, &key);

    printf("key input detected: %s typecode is %i", &key,
           t->cdata.component_typecode);
}

void render_textbox(textbox t) {
    set_cursor_position(t.cdata.x, t.cdata.y);
    printf("Textbox: %s and the typecode is %i", t.text,
           t.cdata.component_typecode);
}

void erase_textbox(textbox t) {
    set_cursor_position(t.cdata.x, t.cdata.y);
    for (int i = 0; i < strlen(t.text) + 9; i++) {
        printf(" ");
    }
}

void release_textbox_resources(textbox *t) { free(t->text); }
