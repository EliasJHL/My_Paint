/*
** EPITECH PROJECT, 2023
** Elias josué HAJJAR LLAUQUEN
** File description:
** project for epitech
*/

#include "../include/my.h"

help_t help[] = {
    {"gum", "Permet de tout gommer."},
    {"pipette", "Prends la couleur."},
    {"pen", "Stylo des plus basiques."},
    {"graffe", "Pour les graffitis."},
    {"piont_rectengle", "Diminue la taille."},
    {"stars", "Augmente la taille"},
    {NULL, NULL}
};

value_t color_list[] = {
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

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;

    for (i = 0; str[i] != '\0'; i++) {
        for (j = 0; to_find[j] != '\0' && str[i + j] == to_find[j]; j++);
        if (to_find[j] == '\0') {
            return &str[i];
        }
    }
    return NULL;
}

int message_check(sfRenderWindow *w, sfText *t, sfVector2f p, button_t *c)
{
    for (int i = 0; help[i].name != NULL; i++) {
        if (my_strcmp(c->name, help[i].name) == 0) {
            sfText_setString(t, help[i].text);
            sfText_setPosition(t, p);
            sfRenderWindow_drawText(w, t, NULL);
            return 1;
        }
    }
    for (int i = 0; color_list[i].name != NULL; i++) {
        if (my_strcmp(c->name, color_list[i].name) == 0) {
            sfText_setString(t, "Change la couleur");
            sfText_setPosition(t, p);
            sfRenderWindow_drawText(w, t, NULL);
            return 1;
        }
    }
    return 0;
}

int message_proc(sfRenderWindow *window, sfText *text, sfVector2f pos,
    button_t *current)
{
    if (current->is_clicked(current, window)) {
        return message_check(window, text, pos, current);
    }
    return 0;
}

sfText *fabric(sfText *text, sfFont *font)
{
    sfVector2f pos = {1580, 980};

    sfText_setScale(text, (sfVector2f){0.8, 0.8});
    sfText_setColor(text, sfBlack);
    sfText_setFont(text, font);
    sfText_setPosition(text, pos);
    return text;
}

static void error_message(sfText *text, sfRenderWindow *window, sfVector2f pos)
{
    sfText_setString(text, "Outil non disponible");
    sfRenderWindow_drawText(window, text, NULL);
    sfText_setPosition(text, pos);
}

void help_message(sfRenderWindow *window, data_t *data)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    sfVector2f pos = {1580, 980};
    button_t *current = data->buttons;
    int status = 0;

    text = fabric(text, font);
    while (current != NULL) {
        if (message_proc(window, text, pos, current) == 1) {
            status = 1;
            break;
        }
        current = current->next;
    }
    if (status == 0) {
        error_message(text, window, pos);
    }
    sfText_destroy(text);
    sfFont_destroy(font);
}
