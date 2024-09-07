#include "component.h"
#include "core.h"

#define TYPECODE_LABEL 0x1

void initialize_component(void *c, int typecode) {
  if (typecode == TYPECODE_LABEL) {
    ((label *)(c))->cdata.full_component = c;
    ((label *)(c))->cdata.component_typecode = typecode;
  }
}

void render(struct component_data c) {
  if (c.component_typecode == TYPECODE_LABEL) {
    render_label(*((label *)(c.full_component)));
  }
}
