#pragma once
#include "components/base.h"

void initialize_component(void *c, int typecode);
void render(void *component);
void expurgate(void *component);

struct component_data *component_to_cdata(void *component);
