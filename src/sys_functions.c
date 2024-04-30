/*
** EPITECH PROJECT, 2023
** Elias josué HAJJAR LLAUQUEN
** File description:
** project for epitech
*/

#include "../include/my.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char *my_strdup(char *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));

    for (int i = 0; i <= my_strlen(src); i++) {
        str[i] = src[i];
    }
    return (str);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        i++;
    if (s1[i] < s2[i])
        return -1;
    if (s1[i] > s2[i])
        return 1;
    if (s1[i] == '\0' && s2[i] != '\0') {
        return -1;
    } else if (s1[i] != '\0' && s2[i] == '\0')
        return 1;
    return 0;
}

sfVector2f coef_mouse(sfRenderWindow *window)
{
    int w = 1920;
    int h = 1080;
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(window);
    sfVector2u size = sfRenderWindow_getSize(window);
    sfVector2f scaledMousePos;

    scaledMousePos.x = (float)mousePos.x / size.x * w - 2;
    scaledMousePos.y = (float)mousePos.y / size.y * (h - 30);
    return scaledMousePos;
}
