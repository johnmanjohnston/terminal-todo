#include <stdio.h>
#include <stdlib.h>
#include "types.h"

int main(void) {
	task t;
	t.info = "beans";

	task a;
	a.info = "this is task 2";

	task b;
	b.info = "QWERTYUIOP";

	group g;
	initialize_group(&g, "group title");

	add_task_to_group(&g, &t);
	add_task_to_group(&g, &a);
	add_task_to_group(&g, &b);

	printf("g.tasks[0].info is %s\n", g.tasks[0].info);
	printf("g.tasks[1].info is %s\n", g.tasks[1].info);
	printf("g.tasks[2].info is %s\n", g.tasks[2].info);
	free(g.tasks);

	printf("\n");
	return EXIT_SUCCESS;
}
