#include "tui/color.h"
#include "tui/component.h"
#include "tui/components/base.h"
#include "tui/core.h"
#include "tui/focus.h"
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

    // INFO: creation and initialization of components
    label l;
    initialize_component(&l, 0x1);
    l.text = "this is a label :)";
    position_component(&l.cdata, 2 + (get_terminal_width()) / 2, 30);

    panel p;
    initialize_component(&p, 0x2);
    position_component(&p.cdata, (get_terminal_width() / 2), 2);
    p.height = 16;
    p.width = 32;

    panel second_panel;
    initialize_component(&second_panel, 0x2);
    position_component(&second_panel.cdata, (get_terminal_width() / 3), 2);
    second_panel.height = 16;
    second_panel.width = 32;

    panel third_panel;
    initialize_component(&third_panel, 0x2);
    position_component(&third_panel.cdata, 30,
                       2); // TODO: let the x value set procedurally
    third_panel.height = 16;
    third_panel.width = 32;

    textbox tbox;
    initialize_component(&tbox, 0x3);
    position_component(&tbox.cdata, p.cdata.x + 2, p.cdata.y + 1);
    // tbox.text = "this is textbox text";
    // strcpy(tbox.text, "this is some textbox text");

    textbox other_tbox;
    initialize_component(&other_tbox, 0x3);
    position_component(&other_tbox.cdata, 32, 32);

    textbox tertiary_textbox;
    initialize_component(&tertiary_textbox, 0x3);
    position_component(&tertiary_textbox.cdata, 28, 28);

    int tick = 0;
    char key = 0;

    int numKeys = 0;
    // render(&l, 0x1);
    // printf("%s", l.text);

    focus_manager fm;
    initialize_focus_manager(&fm, 0);

    // INFO: component focus

    //    fm.focusable_components[0] = (void *)&tbox;
    // fm.focusable_components[1] = (void *)&other_tbox;
    //    add_component_to_focus_list(&fm, &other_tbox.cdata);
    // add_component_to_focus_list(&fm, &tbox.cdata);
    // add_component_to_focus_list(&fm, &tertiary_textbox.cdata);

    add_component_to_focus_list(&fm, &other_tbox.cdata);
    add_component_to_focus_list_with_index(&fm, &tbox.cdata, 0);

    // fill_with_color(background_c()); // 0x282828
    set_text_color(foreground_c()); // 0xCC241D

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
            release_focus_manager_resources(&fm);
            release_textbox_resources(&tbox);
            break;
        }

        if (key == 'p') {
            // fm.focusable_components[2] = fm.focusable_components[1];
            // remove_component_from_focus_list(&fm, &other_tbox.cdata);
            add_component_to_focus_list_with_index(&fm, &tertiary_textbox.cdata,
                                                   0);
            increment_focus(&fm);
        }

        if (key == '\t') {
            increment_focus(&fm);
        }

        if (key > 0) {
            numKeys++;

            // INFO: draw some debug info
            set_cursor_position(0, 0);
            printf("current focus index is %d", fm.current_focus_index);

            for (int i = 0; i < fm.num_components; i++) {

                set_cursor_position(0, 40 + i);
                textbox *t = (textbox *)fm.focusable_components[i];
                printf("textbox with text %s is at focus index %d", t->text, i);
            }

            if (key != '\t') {
                send_key_input_to_focused_component(&fm, key);
            }

            render(&l);
            render(&p);
            render(&second_panel);
            render(&third_panel);

            render(&tbox);
            render(&other_tbox);
            render(&tertiary_textbox);

            if (key == 'p') {
                expurgate(&tbox);
                expurgate(&l);
            }
        }
    }

    reset_terminal_config();

    printf("\n");
    return EXIT_SUCCESS;
}
