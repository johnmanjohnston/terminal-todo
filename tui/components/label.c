#include "label.h"
#include "../core.h"
#include <stdio.h>

void render_label(label l) {
  set_cursor_position(l.cdata.x, l.cdata.y);
  printf("%s", l.text);
}
