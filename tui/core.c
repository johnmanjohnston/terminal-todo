#include "core.h"
#include "stdio.h"
#include "stdlib.h"

#include <unistd.h>
#include <termios.h>

void print_at_coords(int x, int y) {
    char c = 'c';
    printf("\033[%d;%dH%c", x, y, c);
}

void set_terminal_config(void) {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void reset_terminal_config(void) {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ICANON | ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}