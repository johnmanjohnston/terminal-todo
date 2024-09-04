#include <stdio.h>
#include <stdlib.h>
#include "types.h"

int main(void) {
	task t;
	t.info = "beans";

	group g;
	g.task_count = 1;
	g.title = "group titel";

	g.tasks = (task*)malloc(sizeof(task) * g.task_count);

	g.tasks[0] = t;

	printf("g.tasks[0].info is %s", g.tasks[0].info);

	free(g.tasks);

	printf("\n");
	return 0;
}
