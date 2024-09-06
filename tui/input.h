int input_loop(void);

typedef struct {
  int keycode;
  void (*callback)(void);
} input_handler;
