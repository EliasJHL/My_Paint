/*
** EPITECH PROJECT, 2023
** Elias josué HAJJAR LLAUQUEN
** File description:
** project for epitech
*/

#include "../include/my.h"

value_t colors[] = {
    {"Black", 0, 0, 0},
    {"Grey", 102, 103, 102},
    {"Brown", 101, 1, 5},
    {"Green_1", 100, 106, 1},
    {"Green_2", 19, 103, 5},
    {"Blue_1", 16, 107, 102},
    {"Blue_2", 10, 1, 108},
    {"Magneta_1", 100, 1, 105},
    {"Grey_Green", 102, 105, 38},
    {"Green_Obscur", 7, 44, 43},
    {"Blue_clair", 29, 97, 254},
    {"Blue_Obscur", 11, 40, 107},
    {"Blue_Violet", 52, 0, 255},
    {"Brown_2", 100, 42, 1},
    {"White", 255, 255, 255},
    {"Grey_clair", 174, 174, 174},
    {"Red", 241, 1, 9},
    {"Yellow", 252, 253, 1},
    {"Green_3", 41, 250, 8},
    {"Blue_3", 48, 253, 254},
    {"Blue_4", 23, 0, 255},
    {"Magneta_2", 254, 0, 252},
    {"Yellow_2", 252, 255, 86},
    {"Green_5", 49, 252, 84},
    {"Blue_5", 114, 253, 255},
    {"Blue_Violet_1", 107, 96, 253},
    {"Rose", 246, 1, 102},
    {"Orange", 253, 97, 35},
    {NULL, 255, 255, 255},
};

void init_buttons(data_t *data)
{
    sfColor custom;

    data->color_stock = malloc(sizeof(color_t) * 29);
    for (int i = 0; i < 29; i++) {
        if (colors[i].name == NULL) {
            break;
        } else {
            data->color_stock[i].name = my_strdup(colors[i].name);
            custom = sfColor_fromRGB(colors[i].r, colors[i].g, colors[i].b);
            data->color_stock[i].value = custom;
        }
    }
}

void check_color_button(data_t *data, button_t *current)
{
    sfRectangleShape_setFillColor(current->rect, sfRed);
    for (int i = 0; i < 28; i++) {
        if (my_strcmp(current->name, colors[i].name) == 0) {
            data->color[0] = colors[i].r;
            data->color[1] = colors[i].g;
            data->color[2] = colors[i].b;
        }
    }
}
