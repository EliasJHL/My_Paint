/*
** EPITECH PROJECT, 2023
** Elias josué HAJJAR LLAUQUEN
** File description:
** project for epitech
*/

#include "../include/my.h"
#include <stdbool.h>

int erraser(data_t *data, button_t *current, sfRenderWindow *window)
{
    if (my_strcmp(current->name, "gum") == 0) {
        if (current->is_clicked(current, window)) {
            data->color[0] = 255;
            data->color[1] = 255;
            data->color[2] = 255;
            data->size = 10;
            data->tool = ERASER;
            return 1;
        }
    }
    return 0;
}

int graffiti(data_t *data, button_t *current, sfRenderWindow *window)
{
    if (my_strcmp(current->name, "graffe") == 0) {
        if (current->is_clicked(current, window)) {
            data->color[0] = 255;
            data->color[1] = 0;
            data->color[2] = 0;
            data->size = 5;
            data->tool = PENCIL;
            return 1;
        }
    }
    return 0;
}

int pencil(data_t *data, button_t *current, sfRenderWindow *window)
{
    if (my_strcmp(current->name, "pen") == 0) {
        if (current->is_clicked(current, window)) {
            data->color[0] = 0;
            data->color[1] = 0;
            data->color[2] = 0;
            data->size = 1;
            data->tool = PENCIL;
            return 1;
        }
    }
    if (my_strcmp(current->name, "stars") == 0)
        if (current->is_clicked(current, window)) {
            data->size++;
            data->tool = HAND;
            return 1;
        }
    return 0;
}

void get_color(data_t *data, sfRenderWindow *window)
{
    sfVector2f mousePos = coef_mouse(window);
    sfImage *image = sfRenderWindow_capture(window);
    sfColor pixel;

    pixel = sfImage_getPixel(image, mousePos.x, mousePos.y);
    data->color[0] = pixel.r;
    data->color[1] = pixel.g;
    data->color[2] = pixel.b;
}

int pipette(data_t *data, button_t *current, sfRenderWindow *window)
{
    if (my_strcmp(current->name, "pipette") == 0) {
        if (current->is_clicked(current, window)) {
            data->tool = PIPETTE;
            return 0;
        }
    }
    if (my_strcmp(current->name, "piont_rectengle") == 0)
        if (current->is_clicked(current, window)) {
            data->size--;
            data->tool = HAND;
            return 1;
        }
    return 0;
}
