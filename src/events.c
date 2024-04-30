/*
** EPITECH PROJECT, 2023
** Elias josué HAJJAR LLAUQUEN
** File description:
** project for epitech
*/

#include "../include/my.h"
#include <stdbool.h>

//status 1 : Hover | status 2 : click | status 3 : normal
static void cursor_status(sfRenderWindow *window)
{
    sfSprite *mouse_sprite = sfSprite_create();
    sfVector2f mouse_pos = coef_mouse(window);
    sfTexture *texture = NULL;
    sfVector2f pos = (sfVector2f){mouse_pos.x, mouse_pos.y};

    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    texture = sfTexture_createFromFile("assets_mouse/hover.png", NULL);
    sfSprite_setTexture(mouse_sprite, texture, sfTrue);
    sfSprite_setPosition(mouse_sprite, pos);
    sfRenderWindow_drawSprite(window, mouse_sprite, NULL);
    sfSprite_destroy(mouse_sprite);
}

int check_proc(sfRenderWindow *window, data_t *data, int n, button_t *current)
{
    if (current->is_clicked(current, window) && n == 9) {
        check_color_button(data, current);
        cursor_status(window);
        return 0;
    }
    if (current->is_clicked(current, window) && n == 11) {
        if (current->sprite != NULL)
            sfSprite_setColor(current->sprite,
                sfColor_fromRGB(190, 190, 190));
        help_message(window, data);
        sfRectangleShape_setFillColor(current->rect, sfGreen);
        cursor_status(window);
        return 0;
    }
    if (!current->is_clicked(current, window) || n == 10) {
        if (current->sprite != NULL)
            sfSprite_setColor(current->sprite, sfWhite);
        sfRectangleShape_setFillColor(current->rect, sfTransparent);
    }
    return 1;
}

static int tools_change(data_t *data, button_t *current, sfRenderWindow *w)
{
    if (pipette(data, current, w) == 1)
        return 1;
    if (pencil(data, current, w) == 1)
        return 1;
    if (graffiti(data, current, w) == 1)
        return 1;
    if (erraser(data, current, w) == 1)
        return 1;
    return 0;
}

int check_click_on_button(sfRenderWindow *window, sfEvent event, data_t *data)
{
    button_t *current = data->buttons;
    int n = event.type;

    if (data->tool == PIPETTE || data->tool == HAND)
        return 1;
    while (current != NULL) {
        if (check_proc(window, data, n, current) == 0)
            return 0;
        if (tools_change(data, current, window) == 1)
            return 1;
        current = current->next;
    }
    free(current);
    return 1;
}

void save_image(sfRenderWindow *window, sfIntRect area)
{
    sfImage *fullImage = sfRenderWindow_capture(window);
    sfImage *areaImage = sfImage_create(area.width, area.height);
    char *name = "image.jpg";
    sfColor pixel;

    for (int y = 0; y < area.height; y++)
        for (int x = 0; x < area.width; x++) {
            pixel = sfImage_getPixel(fullImage, area.left + x, area.top + y);
            sfImage_setPixel(areaImage, x, y, pixel);
        }
    sfImage_saveToFile(areaImage, name);
    sfImage_destroy(fullImage);
    sfImage_destroy(areaImage);
    sfRenderWindow_close(window);
}

void analyse_event_2(sfEvent event, data_t *data, sfRenderWindow *window)
{
    if (event.type == 11)
        if (data->mouse_state == 1)
            square_draw(coef_mouse(window), data);
    if (event.type == 10) {
        if (event.mouseButton.button == sfMouseLeft) {
            data->mouse_state = 0;
        }
    }
    if (event.type == sfEvtKeyReleased)
        if (event.key.code == sfKeyZ)
            data->ctrl_z_active = false;
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

void analyse_events(sfRenderWindow *window, sfEvent event, data_t *data)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(data->board);
    sfVector2f mouse = coef_mouse(window);

    if (event.type == 9) {
        if (event.mouseButton.button == sfMouseLeft &&
            sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
            data->mouse_state = PRESSED;
            add_next_line(data);
            data->mouse_state = 1;
        }
        if (data->tool == PIPETTE) {
            get_color(data, window);
            data->tool = PENCIL;
            data->mouse_state = 0;
        }
    }
    analyse_event_2(event, data, window);
}
