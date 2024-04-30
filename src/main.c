/*
** EPITECH PROJECT, 2023
** Elias josué HAJJAR LLAUQUEN
** File description:
** project for epitech
*/

#include "../include/my.h"
#include <string.h>
#include <stdbool.h>

void color_button(button_t *current, data_t *data)
{
    color_t *c = data->color_stock;

    for (int i = 0; c[i].name != NULL; i++) {
        if (my_strcmp(c[i].name, current->name) == 0 && data->tool == PENCIL){
            sfRectangleShape_setFillColor(current->rect, c[i].value);
            return;
        }
    }
}

void draw_buttons(sfRenderWindow *window, data_t *data)
{
    button_t *current = data->buttons;
    sfColor custom = sfColor_fromRGB(data->color[0],
        data->color[1], data->color[2]);

    while (current != NULL) {
        if (my_strcmp(current->name, "Color_selected") == 0)
            sfRectangleShape_setFillColor(current->rect, custom);
        color_button(current, data);
        sfRenderWindow_drawRectangleShape(window, current->rect, NULL);
        if (current->sprite != NULL) {
            sfRenderWindow_drawSprite(window, current->sprite, NULL);
        }
        current = current->next;
    }
    free(current);
}

static void render(sfRenderWindow *window, drop_menu_t *menu, data_t *data)
{
    sfRenderWindow_drawRectangleShape(window, menu[0].rect, NULL);
    sfRenderWindow_drawSprite(window, menu[0].sprite, NULL);
    if (data->file_save == true) {
        sfRenderWindow_drawRectangleShape(window, menu[1].rect, NULL);
        sfRenderWindow_drawSprite(window, menu[1].sprite, NULL);
        sfRenderWindow_drawRectangleShape(window, menu[2].rect, NULL);
        sfRenderWindow_drawSprite(window, menu[2].sprite, NULL);
    }
    if (data->size < 1)
        data->size = 1;
    if (data->size > 35)
        data->size = 35;
    display_size(window, data);
    sfRenderWindow_display(window);
}

static void logo(sfRenderWindow *window)
{
    sfTexture *txt = sfTexture_createFromFile("assets/logo.png", NULL);
    sfSprite *logo = sfSprite_create();

    sfSprite_setTexture(logo, txt, sfTrue);
    sfSprite_setPosition(logo, (sfVector2f){35, 12});
    sfSprite_setScale(logo, (sfVector2f){0.2, 0.2});
    sfRenderWindow_drawSprite(window, logo, NULL);
    sfSprite_destroy(logo);
    sfTexture_destroy(txt);
}

void loop_process(sfRenderWindow *window, data_t *data, drop_menu_t *menu)
{
    sfEvent event;
    sfColor bg = sfColor_fromRGBA(82, 83, 82, 255);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, bg);
        hud_handler(window, data);
        draw_buttons(window, data);
        check_shortcuts(data);
        if (check_click_on_button(window, event, data) == 1)
            sfRenderWindow_setMouseCursorVisible(window, sfTrue);
        logo(window);
        if (data->image_loaded != NULL)
            sfRenderWindow_drawSprite(window, data->image_loaded, NULL);
        draw_lines(data, window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            analyse_events(window, event, data);
            drop_menu(data, window, menu, event);
        }
        render(window, menu, data);
    }
}

void starter(data_t *data)
{
    data->color = malloc(sizeof(int) * 3);
    data->color[0] = 0;
    data->color[1] = 0;
    data->color[2] = 0;
    data->image_loaded = NULL;
    data->ctrl_z_active = false;
    data->size = 1;
}

int main(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = NULL;
    data_t *data = malloc(sizeof(data_t));
    drop_menu_t *menu = malloc(sizeof(drop_menu_t) * 3);

    starter(data);
    if (buttons_starter(data) == 84)
        return 84;
    window = sfRenderWindow_create(mode, "Paint", sfClose | sfResize, NULL);
    init_buttons(data);
    whiteboard(data);
    loop_process(window, data, menu);
    sfRenderWindow_destroy(window);
    free(data);
    return 0;
}
