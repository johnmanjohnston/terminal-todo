typedef struct {
	char* info;
} task;

typedef struct {
	char* title;
	task* tasks;
	int task_count;
} group;