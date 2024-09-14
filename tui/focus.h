#include "components/base.h"
typedef struct {
    void **focusable_components;
    int num_components;
    int current_focus_index;
} focus_manager;

// THE FORMATTING PLUGIN I USE MAKES THIS LOOK ABSOLUTELY HORRENDOUS AAAAAAAA
void add_component_to_focus_list(focus_manager *fm,
                                 struct component_data *cdata);
void remove_component_from_focus_list(focus_manager *fm,
                                      struct component_data *cdata);

void release_focus_manager_resources(focus_manager *fm);
void initialize_focus_manager(focus_manager *fm, unsigned int num_components);

void *get_currently_focused_component(focus_manager *fm);
