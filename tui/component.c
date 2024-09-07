#include "component.h"

/*
void position_component(component *component, int x, int y) {
  component->x = x;
  component->y = y;
}
*/

void position_component(struct component_data *c, int x, int y) {
  c->x = x;
  c->y = y;
}
