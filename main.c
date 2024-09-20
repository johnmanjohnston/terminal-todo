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
#include <unistd.h>

#include "tui/components/label.h"
#include "tui/components/panel.h"
#include "tui/components/textbox.h"

#include "tui/extended/group_component.h"

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

    /*
    panel p;
    initialize_component(&p, 0x2);
    position_component(&p.cdata, (get_terminal_width() / 2) - (16 * 3), 2);
    p.height = 16;
    p.width = 32;

    panel second_panel;
    initialize_component(&second_panel, 0x2);
    position_component(&second_panel.cdata, (get_terminal_width() / 2) - 16, 2);
    second_panel.height = 16;
    second_panel.width = 32;

    panel third_panel;
    initialize_component(&third_panel, 0x2);
    position_component(&third_panel.cdata,
                       (get_terminal_width() / 2) + (16 * 1), 2);
    third_panel.height = 16;
    third_panel.width = 32;

    // tbox.text = "this is textbox text";
    // strcpy(tbox.text, "this is some textbox text");

    textbox other_tbox;
    initialize_component(&other_tbox, 0x3);
    position_component(&other_tbox.cdata, 32, 32);

    textbox tertiary_textbox;
    initialize_component(&tertiary_textbox, 0x3);
    position_component(&tertiary_textbox.cdata, 28, 28);
    */

    group_component gc;
    gc.panel.width = 32;
    gc.panel.height = 16;
    position_component(&gc.cdata, (get_terminal_width() / 2) - 16, 2);
    initialize_component(&gc, 0x10);

    group_component other_gc;
    other_gc.panel.width = 32;
    other_gc.panel.height = 16;
    position_component(&other_gc.cdata, (get_terminal_width() / 2) - (16 * 3),
                       2);
    initialize_component(&other_gc, 0x10);

    group_component t_gc;
    t_gc.panel.width = 32;
    t_gc.panel.height = 16;
    position_component(&t_gc.cdata, (get_terminal_width() / 2) + 16, 2);
    initialize_component(&t_gc, 0x10);

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

    fill_with_color(background_c()); // 0x282828
    set_text_color(foreground_c());  // 0xCC241D

    add_component_to_focus_list(&fm, &other_gc.cdata);
    add_component_to_focus_list(&fm, &gc.cdata);
    add_component_to_focus_list(&fm, &t_gc.cdata);

    while (1) {
        tick++;
        key = input_loop();

        if (key == 'q') {

            /*
            FILE *fptr;
            fptr = fopen("../tasks.txt", "w");

            if (fptr == NULL) {
                set_cursor_position(1, 1);
                printf("fptr is NULL");
            } else {
                fputs(tbox.text, fptr);
                fclose(fptr);
            }
            */
            release_focus_manager_resources(&fm);
            release_group_component_resources(&gc);
            release_group_component_resources(&other_gc);
            release_group_component_resources(&t_gc);
            break;
        }

        if (key == '\t') {
            increment_focus(&fm);
        }

        if (key > 0) {
            numKeys++;
            // clear_terminal();

            // INFO: draw some debug info
            set_cursor_position(0, 0);
            printf("current focus index is %d", fm.current_focus_index);

            // ASDKL;FHJASDL; KFH ASKLD JFHASDKF JH THIS WAS CUAINSG SEGFAULT
            // AND I DIDNI'T KNOW I WASTED SO MUCH TIME AKLSDJFHKLAJSDFH
            /*
            for (int i = 0; i < fm.num_components; i++) {

                set_cursor_position(0, 40 + i);
                textbox *t = (textbox *)fm.focusable_components[i];
                printf("textbox with text %s is at focus index %d", t->text, i);
            }
            */

            if (key != '\t') {
                send_key_input_to_focused_component(&fm, key);
            }

            render(&l);

            render(&gc);
            render(&other_gc);
            render(&t_gc);

            if (key == 'p') {
                expurgate(&l);
            }
        }
    }

    reset_terminal_config();

    printf("\n");
    return EXIT_SUCCESS;
}
