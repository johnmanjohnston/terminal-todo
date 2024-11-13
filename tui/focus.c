#include "focus.h"
#include "components/base.h"
#include "core.h"
#include <stdlib.h>
#include <string.h>

// TODO: check for failure of memory allocation functions

// the formatting plugin i use makes everything in this file look absolutely
// horrendous, i apologize future me.

void release_focus_manager_resources(focus_manager *fm) {
    free(fm->focusable_components);
}

void initialize_focus_manager(focus_manager *fm, unsigned int num_components) {
    fm->current_focus_index = 0;
    fm->num_components = num_components;
    fm->focusable_components =
        malloc(sizeof(struct component_data) * num_components);
}

void add_component_to_focus_list_with_index(focus_manager *fm,
                                            struct component_data *cdata,
                                            unsigned int index) {
    fm->num_components++;
    fm->focusable_components =
        realloc(fm->focusable_components,
                sizeof(struct component_data) * fm->num_components);

    for (int i = fm->num_components - 1; i > index; i--) {
        fm->focusable_components[i] = fm->focusable_components[i - 1];
    }

    fm->focusable_components[index] = cdata;
}

// TODO: make this function take a void* componetn instead of a struct
// component_data
void add_component_to_focus_list(focus_manager *fm,
                                 struct component_data *cdata) {
    set_cursor_position(2, 5 + fm->num_components);

    fm->num_components++;
    fm->focusable_components =
        realloc(fm->focusable_components,
                sizeof(struct component_data) * fm->num_components);

    fm->focusable_components[fm->num_components - 1] = (void *)cdata;
}

void remove_component_from_focus_list(focus_manager *fm,
                                      struct component_data *cdata) {
    int index = -1;

    for (int i = 0; i < fm->num_components; i++) {
        if (fm->focusable_components[i] == cdata) {
            index = i;
            break;
        }
    }

    if (index != -1) {

        for (int i = index + 1; i < fm->num_components; i++) {
            fm->focusable_components[i - 1] = fm->focusable_components[i];
        }

        fm->num_components--;

        fm->focusable_components =
            realloc(fm->focusable_components,
                    sizeof(struct component_data) * fm->num_components);
    }
}

void *get_currently_focused_component(focus_manager *fm) {
    struct component_data *cdata =
        (struct component_data
             *)(fm->focusable_components[fm->current_focus_index]);

    return cdata->full_component;
}

void increment_focus(focus_manager *fm) {
    set_cursor_position(20, 1);

    struct component_data *focused_cdata =
        (struct component_data
             *)(fm->focusable_components[fm->current_focus_index]);

    if (focused_cdata->on_blur != NULL)
        focused_cdata->on_blur(get_currently_focused_component(fm));

    focused_cdata->is_focused = 0;

    fm->current_focus_index++;
    fm->current_focus_index %= fm->num_components;

    focused_cdata = (struct component_data
                         *)(fm->focusable_components[fm->current_focus_index]);

    if (focused_cdata->on_focus != NULL)
        focused_cdata->on_focus(get_currently_focused_component(fm));

    focused_cdata->is_focused = 1;
}

void send_key_input_to_focused_component(focus_manager *fm, char key) {
    struct component_data *focused_cdata =
        (struct component_data
             *)(fm->focusable_components[fm->current_focus_index]);

    if (focused_cdata->handle_key_input != NULL)
        focused_cdata->handle_key_input(get_currently_focused_component(fm),
                                        key);
}
