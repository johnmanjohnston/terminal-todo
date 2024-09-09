#pragma once
#include "components/base.h"

void initialize_component(void *c, int typecode);
void render(void *component);
void expurgate(struct component_data c);
