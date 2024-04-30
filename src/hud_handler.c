/*
** EPITECH PROJECT, 2023
** Elias josué HAJJAR LLAUQUEN
** File description:
** project for epitech
*/

#include "../include/my.h"

void whiteboard_ombre(sfRenderWindow *window)
{
    sfRectangleShape *board_om = sfRectangleShape_create();

    sfRectangleShape_setSize(board_om, (sfVector2f){1500, 825});
    sfRectangleShape_setPosition(board_om, (sfVector2f){160, 110});
    sfRectangleShape_setFillColor(board_om,
        sfColor_fromRGBA(40, 40, 40, 255));
    sfRectangleShape_setOutlineThickness(board_om, 0);
    sfRenderWindow_drawRectangleShape(window, board_om, NULL);
}

void whiteboard(data_t *data)
{
    data->board = sfRectangleShape_create();
    sfRectangleShape_setSize(data->board, (sfVector2f){1500, 825});
    sfRectangleShape_setPosition(data->board, (sfVector2f){150, 100});
    sfRectangleShape_setFillColor(data->board,
        sfColor_fromRGBA(255, 255, 255, 255));
    sfRectangleShape_setOutlineThickness(data->board, 0);
    sfRectangleShape_setOutlineColor(data->board,
        sfColor_fromRGBA(20, 20, 20, 255));
}

void color_selector(sfRenderWindow *window, data_t *data)
{
    sfRectangleShape *color = sfRectangleShape_create();

    sfRectangleShape_setSize(color, (sfVector2f){1920, 140});
    sfRectangleShape_setPosition(color, (sfVector2f){0, 950});
    sfRectangleShape_setFillColor(color, sfColor_fromRGBA(174, 174, 174, 255));
    sfRectangleShape_setOutlineThickness(color, 3);
    sfRectangleShape_setOutlineColor(color, sfColor_fromRGBA(20, 20, 20, 255));
    sfRenderWindow_drawRectangleShape(window, color, NULL);
    sfRenderWindow_drawRectangleShape(window, data->board, NULL);
    sfRectangleShape_destroy(color);
}

void tools_gui(sfRenderWindow *window, data_t *data)
{
    sfRectangleShape *files = sfRectangleShape_create();

    sfRectangleShape_setSize(files, (sfVector2f){1920, 75});
    sfRectangleShape_setPosition(files, (sfVector2f){0, 0});
    sfRectangleShape_setFillColor(files, sfColor_fromRGBA(174, 174, 174, 255));
    sfRectangleShape_setOutlineThickness(files, 3);
    sfRectangleShape_setOutlineColor(files, sfColor_fromRGBA(20, 20, 20, 255));
    sfRenderWindow_drawRectangleShape(window, files, NULL);
    color_selector(window, data);
    sfRectangleShape_destroy(files);
}

void hud_handler(sfRenderWindow *window, data_t *data)
{
    sfRectangleShape *tools = sfRectangleShape_create();

    whiteboard_ombre(window);
    sfRectangleShape_setSize(tools, (sfVector2f){130, 1080});
    sfRectangleShape_setPosition(tools, (sfVector2f){0, 0});
    sfRectangleShape_setFillColor(tools, sfColor_fromRGBA(174, 174, 174, 255));
    sfRectangleShape_setOutlineThickness(tools, 4);
    sfRectangleShape_setOutlineColor(tools, sfColor_fromRGBA(20, 20, 20, 255));
    sfRenderWindow_drawRectangleShape(window, tools, NULL);
    tools_gui(window, data);
    sfRectangleShape_destroy(tools);
}
