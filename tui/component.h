#pragma once
#include "components/base.h"

void initialize_component(void *c, int typecode);
void render(void *component);
void expurgate(void *component);

void set_cdata_to_non_interactable(struct component_data *cdata);
void set_cdata_to_interactable(struct component_data *cdata);

struct component_data *component_to_cdata(void *component);
