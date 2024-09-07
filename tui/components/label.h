#include "base.h"

typedef struct {
  struct component_data cdata;
  char *text;
} label;

void render_label(label l);
