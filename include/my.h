/*
** EPITECH PROJECT, 2023
** Elias josué HAJJAR LLAUQUEN
** File description:
** project for epitech
*/

#pragma once
#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <SFML/System.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

enum e_gui_state {
    NONE = 0,
    HOVER,
    PRESSED,
    RELEASED
};

enum tools {
    PENCIL = 0,
    GRAFFITI,
    ERASER,
    MENU,
    PIPETTE,
    HAND
};

typedef struct button_s {
    char *name;
    char *text_path;
    int visible;
    int bordure;
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f size;
    sfRectangleShape *rect;
    struct button_s *next;
    enum e_gui_state state;
    sfBool (*is_clicked)(struct button_s *, sfRenderWindow *);
}button_t;

typedef struct lines {
    sfVertexArray *array;
    struct lines *next;
} lines_t;

typedef struct value_s {
    char *name;
    int r;
    int g;
    int b;
} value_t;

typedef struct color_s {
    char *name;
    sfColor value;
} color_t;

typedef struct help_s {
    char *name;
    char *text;
} help_t;

typedef struct drop_menu_s {
    sfRectangleShape *rect;
    sfSprite *sprite;
    sfBool visible;
    sfBool is_clicked;
} drop_menu_t;

typedef struct object {
    int size;
    int *color;
    int mouse_state;
    sfBool file_save;
    lines_t *lines;
    enum tools tool;
    sfImage *capture;
    sfColor color_pen;
    button_t *buttons;
    color_t *color_stock;
    sfBool ctrl_z_active;
    sfSprite *image_loaded;
    sfRectangleShape *board;
} data_t;

void get_color(data_t *data, sfRenderWindow *window);

void square_draw(sfVector2f point, data_t *data);

void help_message(sfRenderWindow *window, data_t *data);

int pipette(data_t *data, button_t *current, sfRenderWindow *window);

void analyse_events(sfRenderWindow *, sfEvent, data_t *);

void display_size(sfRenderWindow *window, data_t *data);

sfVector2f coef_mouse(sfRenderWindow *window);

int drop_menu(data_t *data, sfRenderWindow *window,
    drop_menu_t *menu, sfEvent event);

void save_image(sfRenderWindow *window, sfIntRect area);

void init_buttons(data_t *data);

void hud_handler(sfRenderWindow *window, data_t *data);

int erraser(data_t *data, button_t *current, sfRenderWindow *window);

int graffiti(data_t *data, button_t *current, sfRenderWindow *window);

int pencil(data_t *data, button_t *current, sfRenderWindow *window);

void remove_last_line(data_t *);

int check_click_on_button(sfRenderWindow *, sfEvent, data_t *);

void draw_lines(data_t *, sfRenderWindow *);

lines_t *create_line(void);

void whiteboard(data_t *data);

void check_color_button(data_t *data, button_t *current);

void check_shortcuts(data_t *data);

int my_strcmp(char const *s1, char const *s2);

void add_next_line(data_t *);

int buttons_starter(data_t *);

char *my_strdup(char *src);

int my_strlen(char *str);

void window_save(void);
