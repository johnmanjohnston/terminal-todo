#include "tui/color.h"
#include "tui/component.h"
#include "tui/components/base.h"
#include "tui/core.h"
#include "tui/input.h"
#include "tui/utility.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "tui/components/label.h"
#include "tui/components/panel.h"
#include "tui/components/textbox.h"

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
    initialize_component(&l, 0x1);
    l.text = "this is a label :)";
    position_component(&l.cdata, 2 + (get_terminal_width()) / 2, 30);

    panel p;
    initialize_component(&p, 0x2);
    position_component(&p.cdata, (get_terminal_width() / 2), 2);
    p.height = 16;
    p.width = 32;

    textbox tbox;
    initialize_component(&tbox, 0x3);
    position_component(&tbox.cdata, p.cdata.x + 2, p.cdata.y + 1);
    // tbox.text = "this is textbox text";

    input_handler ih;
    ih.callback = testfunc;
    // ih.callback();

    int tick = 0;
    char key = 0;

    int numKeys = 0;
    // render(&l, 0x1);
    // printf("%s", l.text);

    fill_with_color(background_c()); // 0x282828
    set_text_color(foreground_c());  // 0xCC241D

    // l.cdata.render(l);
    while (1) {
        tick++;
        key = input_loop();

        if (key == 'q') {

            FILE *fptr;
            fptr = fopen("../tasks.txt", "w");

            if (fptr == NULL) {
                set_cursor_position(1, 1);
                printf("fptr is NULL");
            } else {
                fputs(tbox.text, fptr);
                fclose(fptr);
            }
            release_textbox_resources(&tbox);
            break;
        }

        if (key > 0) {
            ih.callback();
            numKeys++;

            expurgate(&p);

            tbox.cdata.handle_key_input(&tbox, key);

            // p.width++;

            render(&l);
            render(&p);
            draw_horizontal_line(p.cdata.x, p.cdata.y + 2, p.width, NULL, NULL,
                                 NULL);

            set_text_color(red_c());
            render(&tbox);
            set_text_color(foreground_c());

            if (key == 'p') {
                expurgate(&tbox);
                expurgate(&l);
            }
        }
        set_cursor_position(20, 20);
        printf("num keys: %i", numKeys);

        set_cursor_position(10, 10);
        printf("%i", tick);
    }

    reset_terminal_config();

    printf("\n");
    return EXIT_SUCCESS;
}
