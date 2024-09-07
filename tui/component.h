struct component_data {
  int x;
  int y;
  int component_typecode;
  void *full_component;
};

typedef struct {
  struct component_data cdata;
  char *text;
} label;

void initialize_component(void *c, int typecode);
void render(struct component_data c);
// void render(struct component_data *full_component, int type);
void position_component(struct component_data *c, int x, int y);

// void position_component(component *component, int x, int y);
