struct component_data {
  int x;
  int y;
  int component_typecode;
  void *full_component;
};

void position_component(struct component_data *c, int x, int y);
