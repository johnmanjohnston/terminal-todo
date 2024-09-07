#include "component.h"
#include "core.h"
#include <stdio.h>

/*
void position_component(component *component, int x, int y) {
  component->x = x;
  component->y = y;
}
*/

/*
void render(struct component_data *full_component, int type) {
  if (type == TYPE_LABEL) {
    int x = ((label *)(full_component))->cdata.x;
    int y = ((label *)(full_component))->cdata.y;
    char *data = ((label *)(full_component))->text;
    printf("%s", data);
  }
}*/

#define TYPECODE_LABEL 0x1

void initialize_component(void *c, int typecode) {
  if (typecode == TYPECODE_LABEL) {
    ((label *)(c))->cdata.full_component = c;
    ((label *)(c))->cdata.component_typecode = typecode;
  }
}

void render(struct component_data c) {
  if (c.component_typecode == TYPECODE_LABEL) {
    set_cursor_position(c.x, c.y);
    char *data = ((label *)(c.full_component))->text;
    printf("%s", data);
  }
}

void position_component(struct component_data *c, int x, int y) {
  c->x = x;
  c->y = y;
}
