/*
** EPITECH PROJECT, 2023
** Elias josué HAJJAR LLAUQUEN
** File description:
** project for epitech
*/

#include "../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int k = 0;

    while (dest[k] != '\0') {
        k++;
    }
    while (src[i] != '\0') {
        dest[i + k] = src[i];
        i++;
    }
    dest[i + k] = '\0';
    return dest;
}

char *int_to_str(int nb)
{
    int i = 0;
    int j = 0;
    char tmp;
    char *str = malloc(sizeof(char) * 2);

    while (nb > 0) {
        str[i] = (nb % 10) + 48;
        nb = nb / 10;
        i++;
    }
    str[i] = '\0';
    i--;
    while (i > j) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i--;
        j++;
    }
    return str;
}

void display_size(sfRenderWindow *window, data_t *data)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    sfVector2f pos = {10, 580};
    char *str = NULL;

    str = my_strdup("Size: ");
    my_strcat(str, int_to_str(data->size));
    sfText_setScale(text, (sfVector2f){0.5, 0.5});
    sfText_setColor(text, sfBlack);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, pos);
    sfText_setString(text, str);
    sfRenderWindow_drawText(window, text, NULL);
    free(str);
    sfFont_destroy(font);
    sfText_destroy(text);
}
