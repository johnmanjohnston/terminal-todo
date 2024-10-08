#include "component.h"
#include "components/base.h"
#include "components/label.h"
#include "components/panel.h"
#include "components/textbox.h"
#include "core.h"
#include "extended/group_component.h"
#include "extended/task_component.h"

// using hex makes me feel cool
#define TYPECODE_LABEL 0x1
#define TYPECODE_PANEL 0x2
#define TYPECODE_TEXTBOX 0x3
#define TYPECODE_GROUP_COMPONENT 0x10
#define TYPECODE_TASK_COMPONENT 0x11

struct component_data *component_to_cdata(void *component) {
    struct component_data *c = (struct component_data *)component;
    return c;
}

void set_cdata_to_non_interactable(struct component_data *cdata) {
    cdata->takes_input = 0;
    cdata->focusable = 0;
}

void set_cdata_to_interactable(struct component_data *cdata) {
    cdata->takes_input = 1;
    cdata->focusable = 1;
}

void initialize_component(void *c, int typecode) {
    struct component_data *cdata = component_to_cdata(c);
    cdata->component_typecode = typecode;
    cdata->full_component = c;

    // non interactable components
    if (typecode == TYPECODE_LABEL)
        set_cdata_to_non_interactable(cdata);
    else if (typecode == TYPECODE_PANEL)
        set_cdata_to_non_interactable(cdata);

    // interactable components
    if (typecode == TYPECODE_TEXTBOX) {
        set_cdata_to_interactable(cdata);

        ((textbox *)(c))->text = "UNSET TEXT";
        initialize_textbox(((textbox *)(c)));
        cdata->handle_key_input = handle_textbox_key_input;
        cdata->on_blur = textbox_blur;
        cdata->on_focus = textbox_focus;
    }

    if (typecode == TYPECODE_GROUP_COMPONENT) {
        set_cdata_to_interactable(cdata);
        set_cdata_to_interactable(&((group_component *)(c))->textbox.cdata);
        cdata->on_blur = group_component_blur;
        cdata->on_focus = group_component_focus;
        cdata->handle_key_input = handle_group_component_key_input;
        initialize_group_component(((group_component *)(c)));
    }

    // WARN: untested
    if (typecode == TYPECODE_TASK_COMPONENT) {
        set_cdata_to_interactable(cdata);
        set_cdata_to_interactable(&((task_component *)(c))->textbox.cdata);
        cdata->on_blur = task_component_blur;
        cdata->on_focus = task_component_focus;
        cdata->handle_key_input = handle_task_component_key_input;
        initialize_task_component(((task_component *)(c)));
    }
}

void render(void *component) {
    struct component_data c = *component_to_cdata(component);

    if (c.component_typecode == TYPECODE_LABEL) {
        render_label(*((label *)(c.full_component)));
    }

    else if (c.component_typecode == TYPECODE_PANEL) {
        render_panel(*((panel *)(c.full_component)), 1);
    }

    else if (c.component_typecode == TYPECODE_TEXTBOX) {
        render_textbox(*((textbox *)(c.full_component)));
    }

    else if (c.component_typecode == TYPECODE_GROUP_COMPONENT) {
        render_group_component(*(group_component *)(c.full_component));
    }

    else if (c.component_typecode == TYPECODE_TASK_COMPONENT) {
        render_task_component(*(task_component *)(c.full_component));
    }
}

void expurgate(void *component) {
    struct component_data c = *component_to_cdata(component);

    if (c.component_typecode == TYPECODE_LABEL) {
        erase_label(*(label *)(c.full_component));
    }

    else if (c.component_typecode == TYPECODE_PANEL) {
        erase_panel(*(panel *)(c.full_component));
    }

    else if (c.component_typecode == TYPECODE_TEXTBOX) {
        erase_textbox(*((textbox *)(c.full_component)));
    }

    else if (c.component_typecode == TYPECODE_GROUP_COMPONENT) {
        erase_group_component(*(group_component *)(c.full_component));
    }

    else if (c.component_typecode == TYPECODE_TASK_COMPONENT) {
        erase_task_component(*(task_component *)(c.full_component));
    }
}
