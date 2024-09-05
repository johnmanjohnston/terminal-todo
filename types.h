typedef struct {
	char* info;
} task;

typedef struct {
	char* title;
	task* tasks;
	int task_count;
} group;

void initialize_group(group *g, char* title);
void add_task_to_group(group *g, task *t);