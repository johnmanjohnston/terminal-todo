struct component_data {
  int x;
  int y;
};

typedef struct {
  struct component_data cdata;
  char *text;
} label;

void position_component(struct component_data *c, int x, int y);

// void position_component(component *component, int x, int y);
