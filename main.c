#include "tui/core.h"
#include "tui/input.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

  int tick = 0;
  char key = 0;

  int numKeys = 0;

  while (1) {
    tick++;
    key = input_loop();

    if (key == 'q')
      break;

    if (key > 0)
      numKeys++;

    set_cursor_position(20, 20);
    printf("num keys: %i", numKeys);

    set_cursor_position(10, 10);
    printf("%i", tick);
  }

  reset_terminal_config();

  printf("\n");
  return EXIT_SUCCESS;
}
