/*
** EPITECH PROJECT, 2023
** Elias josué HAJJAR LLAUQUEN
** File description:
** project for epitech
*/

#include "../include/my.h"
#include <stdbool.h>

int is_clicked_menu(sfRectangleShape *rect, sfRenderWindow *window)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(rect);
    sfVector2f mousePos = coef_mouse(window);

    if (sfFloatRect_contains(&bounds, mousePos.x, mousePos.y))
        return 1;
    else
        return 0;
}

sfSprite *sprite_create(char *path, sfVector2f position)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    sfFloatRect sprite;
    sfVector2f btn;
    sfVector2f scale;
    sfSprite *res;

    res = sfSprite_create();
    sfSprite_setTexture(res, texture, sfTrue);
    sfSprite_setPosition(res, position);
    sprite = sfSprite_getGlobalBounds(res);
    btn = (sfVector2f){150, 50};
    scale = (sfVector2f){btn.x / sprite.width, btn.y / sprite.height};
    sfSprite_setScale(res, scale);
    return res;
}

static void drop_menu_file(drop_menu_t *menu, int i, int s)
{
    sfRectangleShape *file = sfRectangleShape_create();
    sfColor color = sfColor_fromRGBA(174, 174, 174, 255);

    sfRectangleShape_setPosition(file, (sfVector2f){150, s});
    sfRectangleShape_setSize(file, (sfVector2f){150, 50});
    sfRectangleShape_setFillColor(file, color);
    sfRectangleShape_setOutlineThickness(file, 1);
    sfRectangleShape_setOutlineColor(file, sfBlack);
    menu[i].rect = file;
    if (i == 1)
        menu[i].sprite = sprite_create("assets/sb.png", (sfVector2f){150, s});
    if (i == 2)
        menu[i].sprite = sprite_create("assets/lb.png", (sfVector2f){150, s});
    if (i == 0)
        menu[i].sprite = sprite_create("assets/fd.png", (sfVector2f){150, s});
}

void disable_menu(data_t *data, sfRenderWindow *window, drop_menu_t *menu)
{
    if (!is_clicked_menu(menu[1].rect, window) && data->file_save)
        if (!is_clicked_menu(menu[2].rect, window))
            data->file_save = false;
}

static void event_2(drop_menu_t *menu, sfRenderWindow *window, data_t *data)
{
    sfColor color = sfColor_fromRGBA(174, 174, 174, 255);
    sfColor color2 = sfColor_fromRGBA(120, 120, 120, 255);

    if (data->file_save == true) {
        sfRectangleShape_setFillColor(menu->rect, color2);
        data->tool = MENU;
        menu[0].visible = true;
    } else {
        menu[0].visible = false;
        data->tool = PENCIL;
        sfRectangleShape_setFillColor(menu->rect, color);
    }
    if (!is_clicked_menu(menu[0].rect, window) && data->file_save)
        disable_menu(data, window, menu);
}

static void event_handler(drop_menu_t *m, sfRenderWindow *window, data_t *data)
{
    sfColor color = sfColor_fromRGBA(120, 120, 120, 255);

    if (is_clicked_menu(m[0].rect, window) == 1)
        data->file_save = true;
    if (is_clicked_menu(m[1].rect, window) == 1 && data->file_save) {
        sfRectangleShape_setFillColor(m[1].rect, color);
        data->file_save = true;
    }
    if (is_clicked_menu(m[2].rect, window) == 1 && data->file_save) {
        sfRectangleShape_setFillColor(m[2].rect, color);
        data->file_save = true;
    }
    event_2(m, window, data);
}

sfSprite *load(data_t *data)
{
    sfTexture *texture = sfTexture_createFromFile("image.jpg", NULL);
    sfSprite *res = sfSprite_create();
    sfFloatRect load;
    sfVector2f pos;
    sfVector2f scale;

    sfSprite_setTexture(res, texture, sfTrue);
    sfSprite_setPosition(res, (sfVector2f){150, 100});
    load = sfSprite_getGlobalBounds(res);
    pos = sfRectangleShape_getSize(data->board);
    scale = (sfVector2f){pos.x / load.width, pos.y / load.height};
    sfSprite_setScale(res, scale);
    return res;
}

static void click_handler(drop_menu_t *m, sfRenderWindow *w, data_t *d)
{
    sfVector2u calc;

    if (is_clicked_menu(m[1].rect, w) && m[0].visible) {
        calc = sfRenderWindow_getSize(w);
        window_save();
        write(1, "image saved !\n", 14);
        save_image(w, (sfIntRect) {150, 100,
            calc.x - 420, calc.y - 195});
    }
    if (is_clicked_menu(m[2].rect, w)) {
        d->image_loaded = load(d);
    }
}

int drop_menu(data_t *d, sfRenderWindow *w, drop_menu_t *m, sfEvent event)
{
    int size = 10;
    int c = 0;

    for (int i = 0; i < 3; i++) {
        drop_menu_file(m, c, size);
        size += 50;
        c++;
    }
    if (event.type == sfEvtMouseEntered)
        event_handler(m, w, d);
    if (event.type == 10) {
        click_handler(m, w, d);
    }
    return 0;
}
