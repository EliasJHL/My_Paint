/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-mypaint-pierrik.clary
** File description:
** window_save.c
*/

#include "../include/my.h"

void sprite_message(sfRenderWindow *w)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture;
    sfVector2f pos = {10, -100};

    texture = sfTexture_createFromFile("assets/save_the_draw.png", NULL);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(w, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

void window_save(void)
{
    sfVideoMode m = {660, 120, 32};
    sfRenderWindow *w = sfRenderWindow_create(m, "save", sfDefaultStyle, NULL);
    sfClock *clock = sfClock_create();
    sfTime time;
    float seconds;

    while (sfRenderWindow_isOpen(w)) {
        sfRenderWindow_clear(w, sfWhite);
        sprite_message(w);
        time = sfClock_getElapsedTime(clock);
        seconds = sfTime_asSeconds(time);
        if (seconds > 3.000000)
            break;
        sfRenderWindow_display(w);
    }
    sfRenderWindow_destroy(w);
    sfClock_destroy(clock);
}
