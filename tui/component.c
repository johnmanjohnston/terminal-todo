#include "component.h"
#include "components/base.h"
#include "components/label.h"
#include "components/panel.h"
#include "core.h"

#include <stdio.h>

// using hex makes me feel cool
#define TYPECODE_LABEL 0x1
#define TYPECODE_PANEL 0x2

struct component_data *component_to_cdata(void *component) {
    struct component_data *c = (struct component_data *)component;
    return c;
}

void initialize_component(void *c, int typecode) {
    struct component_data *cdata = component_to_cdata(c);
    cdata->component_typecode = typecode;
    cdata->full_component = c;
}

void render(void *component) {
    struct component_data c = *component_to_cdata(component);

    if (c.component_typecode == TYPECODE_LABEL) {
        render_label(*((label *)(c.full_component)));
    }

    else if (c.component_typecode == TYPECODE_PANEL) {
        render_panel(*((panel *)(c.full_component)));
    }
}

void expurgate(void *component) {
    struct component_data c = *component_to_cdata(component);

    if (c.component_typecode == TYPECODE_LABEL) {
        // TODO: create erasure function for label
    }

    else if (c.component_typecode == TYPECODE_PANEL) {
        erase_panel(*(panel *)(c.full_component));
    }
}
