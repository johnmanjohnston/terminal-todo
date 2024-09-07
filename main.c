#include "tui/component.h"
#include "tui/core.h"
#include "tui/input.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void testfunc(void) { printf("this is called from testfunc()"); }

int main(void) {
  // task t;
  // t.info = "beans";

  // task a;
  // a.info = "this is task 2";

  // task b;
  // b.info = "QWERTYUIOP";

  // group g;
  // initialize_group(&g, "group title");

  // add_task_to_group(&g, &t);
  // add_task_to_group(&g, &a);
  // add_task_to_group(&g, &b);

  // printf("g.tasks[0].info is %s\n", g.tasks[0].info);
  // printf("g.tasks[1].info is %s\n", g.tasks[1].info);
  // printf("g.tasks[2].info is %s\n", g.tasks[2].info);
  // free(g.tasks);
  set_terminal_config();
  clear_terminal();

  label l;
  // l.cdata.x = 5;
  // l.cdata.y = 7;
  // l.cdata.render = render_label;

  initialize_component(&l, 0x1);
  position_component(&l.cdata, 5, 7);
  l.text = "this is some text inside a label";

  input_handler ih;
  ih.callback = testfunc;
  // ih.callback();

  int tick = 0;
  char key = 0;

  int numKeys = 0;
  // render(&l, 0x1);
  set_cursor_position(l.cdata.x, l.cdata.y);
  // printf("%s", l.text);

  // l.cdata.render(l);

  while (1) {
    tick++;
    key = input_loop();

    if (key == 'q')
      break;

    if (key > 0) {
      ih.callback();
      numKeys++;
      render(l.cdata);
    }

    // render(l.cdata);

    set_cursor_position(20, 20);
    printf("num keys: %i", numKeys);

    set_cursor_position(10, 10);
    printf("%i", tick);
  }

  reset_terminal_config();

  printf("\n");
  return EXIT_SUCCESS;
}
