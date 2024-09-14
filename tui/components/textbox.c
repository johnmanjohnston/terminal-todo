#include "textbox.h"
#include "../core.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEXTBOX_BUFFER_SIZE 128

void initialize_textbox(textbox *t) {
    t->text = malloc(TEXTBOX_BUFFER_SIZE); // *sigh*

    t->text[0] = '\0';
    if (t->text == NULL) {
        set_cursor_position(16, 16);
        printf("T->TEXT COULD NOT ALLOCATE MEMORY");
    }
}

void handle_textbox_key_input(void *component, char key) {
    textbox *t = ((textbox *)(component));
    set_cursor_position(0, 0);

    int text_length = strlen(t->text);

    // handle backspace
    if ((int)key == 127 && text_length > 0) {
        t->text[strlen(t->text) - 1] = '\0';
        return;
    }

    // prevent buffer overflow
    if (text_length < TEXTBOX_BUFFER_SIZE - 1) {
        // strcat(t->text, &key);
        t->text[text_length] = key;
        t->text[text_length + 1] = '\0';

        printf("length of text is %d, the latest charcode is %d",
               (int)(strlen(t->text)), (int)key);
    } else {
        printf("textbox text exceeding buffer size");
    }
}

void render_textbox(textbox t) {
    set_cursor_position(t.cdata.x, t.cdata.y);
    for (int i = 0; i < strlen(t.text) + 1; i++) {
        printf(" ");
    }

    set_cursor_position(t.cdata.x, t.cdata.y);
    printf("%s", t.text);
}

void erase_textbox(textbox t) {
    set_cursor_position(t.cdata.x, t.cdata.y);
    for (int i = 0; i < strlen(t.text); i++) {
        printf(" ");
    }
}

void release_textbox_resources(textbox *t) { free(t->text); }
