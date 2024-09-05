#include <stdio.h>
#include <stdlib.h>
#include "types.h"

void initialize_group(group *g, char *title)
{
    g->tasks = NULL;
    g->task_count = 0;
    g->title = title;
}

void add_task_to_group(group *g, task *t)
{
    g->tasks = (task*)realloc(g->tasks, sizeof(task) * (g->task_count + 1));
    g->tasks[g->task_count] = *t;
    g->task_count++;
}
