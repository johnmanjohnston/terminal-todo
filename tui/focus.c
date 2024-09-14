#include "focus.h"
#include "components/base.h"
#include <stdlib.h>

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

void add_component_to_focus_list(focus_manager *fm,
                                 struct component_data *cdata) {
    fm->num_components++;
    fm->focusable_components =
        realloc(fm->focusable_components,
                sizeof(struct component_data) * fm->num_components);

    fm->focusable_components[fm->num_components - 1] = (void *)cdata;
}

// FIXME: this function does not work as expected
void remove_component_from_focus_list(focus_manager *fm,
                                      struct component_data *cdata) {
    fm->focusable_components[fm->num_components - 1] = NULL;
    fm->num_components--;
    fm->focusable_components =
        realloc(fm->focusable_components,
                sizeof(struct component_data) * fm->num_components);
}

void *get_currently_focused_component(focus_manager *fm) {
    struct component_data *cdata =
        (struct component_data
             *)(fm->focusable_components[fm->current_focus_index]);

    void *retval = cdata->full_component;

    return retval;
}
