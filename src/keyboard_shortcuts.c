/*
** EPITECH PROJECT, 2023
** Elias josué HAJJAR LLAUQUEN
** File description:
** project for epitech
*/

#include "../include/my.h"
#include <stdbool.h>

void ctrl_z(data_t *data)
{
    if (data->ctrl_z_active)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyLControl)) {
        if (sfKeyboard_isKeyPressed(sfKeyZ)) {
            remove_last_line(data);
            data->ctrl_z_active = true;
        }
    }
}

void check_shortcuts(data_t *data)
{
    ctrl_z(data);
}
