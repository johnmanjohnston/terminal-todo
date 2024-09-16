#include "components/base.h"
typedef struct {
    void **focusable_components;
    int num_components;
    int current_focus_index;
} focus_manager;

// TODO: organize
void add_component_to_focus_list(focus_manager *fm,
                                 struct component_data *cdata);
void remove_component_from_focus_list(focus_manager *fm,
                                      struct component_data *cdata);

void add_component_to_focus_list_with_index(focus_manager *fm,
                                            struct component_data *cdata,
                                            unsigned int index);

void release_focus_manager_resources(focus_manager *fm);
void initialize_focus_manager(focus_manager *fm, unsigned int num_components);

void increment_focus(focus_manager *fm);
void send_key_input_to_focused_component(focus_manager *fm, char key);

void *get_currently_focused_component(focus_manager *fm);
