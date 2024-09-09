#include "component.h"
#include "components/base.h"
#include "components/label.h"
#include "components/panel.h"
#include "core.h"

// using hex makes me feel cool
#define TYPECODE_LABEL 0x1
#define TYPECODE_PANEL 0x2

void initialize_component(void *c, int typecode) {
    if (typecode == TYPECODE_LABEL) {
        ((label *)(c))->cdata.full_component = c;
        ((label *)(c))->cdata.component_typecode = typecode;
    }

    if (typecode == TYPECODE_PANEL) {
        ((panel *)(c))->cdata.full_component = c;
        ((panel *)(c))->cdata.component_typecode = typecode;
    }
}

void render(void *component) {
    struct component_data c = *(struct component_data *)component;
    if (c.component_typecode == TYPECODE_LABEL) {
        render_label(*((label *)(c.full_component)));
    }

    else if (c.component_typecode == TYPECODE_PANEL) {
        render_panel(*((panel *)(c.full_component)));
    }
}

void expurgate(struct component_data c) {
    if (c.component_typecode == TYPECODE_LABEL) {
        // TODO: create erasure function for label
    }

    else if (c.component_typecode == TYPECODE_PANEL) {
        erase_panel(*((panel *)(c.full_component)));
    }
}
