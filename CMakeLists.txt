cmake_minimum_required(VERSION 3.10)
project(todo)
set(SOURCES main.c types.c tui/component.c tui/core.c tui/input.c tui/components/base.c tui/components/label.c tui/components/panel.c tui/components/textbox.c)
add_executable(todo_ex ${SOURCES})
