/*
** EPITECH PROJECT, 2023
** Elias josué HAJJAR LLAUQUEN
** File description:
** project for epitech
*/

#include "../include/my.h"

int is_clicked(struct button_s *button, sfRenderWindow *window)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(button->rect);
    sfVector2f mousePos = coef_mouse(window);

    if (sfFloatRect_contains(&bounds, mousePos.x, mousePos.y))
        return 1;
    else
        return 0;
}

static int is_delim(char c, char *delim)
{
    int i = 0;

    while (delim[i] != '\0') {
        if (c == delim[i])
            return 1;
        i++;
    }
    return 0;
}

char *my_strtok(char *str, char *delim)
{
    static char *save = NULL;
    char *res = NULL;

    if (str != NULL)
        save = str;
    if (save == NULL)
        return NULL;
    for (int i = 0; save[i] != '\0'; i++) {
        if (is_delim(save[i], delim) == 1) {
            save[i] = '\0';
            res = save;
            save = &save[i + 1];
            return res;
        }
    }
    res = save;
    save = NULL;
    return res;
}

int my_getnbr(char *str)
{
    int i = 0;
    int neg = 1;
    int res = 0;

    if (str[0] == '-') {
        neg = -1;
        i++;
    }
    while (str[i] != '\0') {
        res = res * 10 + str[i] - 48;
        i++;
    }
    return res * neg;
}

static void add_new_node(char *line, button_t *newNode)
{
    newNode->rect = sfRectangleShape_create();
    newNode->name = my_strdup(my_strtok(line, " "));
    newNode->position.x = my_getnbr(my_strtok(NULL, " "));
    newNode->position.y = my_getnbr(my_strtok(NULL, " "));
    newNode->size.x = my_getnbr(my_strtok(NULL, " "));
    newNode->size.y = my_getnbr(my_strtok(NULL, " "));
    newNode->bordure = my_getnbr(my_strtok(NULL, " "));
    newNode->text_path = my_strdup(my_strtok(NULL, " "));
    newNode->is_clicked = is_clicked;
    newNode->state = NONE;
    newNode->next = NULL;
}

static void add_chained_list(data_t *data, char *line)
{
    button_t *current = data->buttons;
    button_t *newNode = malloc(sizeof(struct button_s));

    add_new_node(line, newNode);
    if (current == NULL) {
        data->buttons = newNode;
    } else {
        while (current->next != NULL)
            current = current->next;
        current->next = newNode;
    }
}

static void sprite_create(button_t *current)
{
    sfTexture *texture = sfTexture_createFromFile(current->text_path, NULL);
    sfFloatRect sprite;
    sfVector2f btn;
    sfVector2f scale;

    current->sprite = sfSprite_create();
    sfSprite_setTexture(current->sprite, texture, sfTrue);
    sfSprite_setPosition(current->sprite, current->position);
    sprite = sfSprite_getGlobalBounds(current->sprite);
    btn = (sfVector2f){current->size.x, current->size.y};
    scale = (sfVector2f){btn.x / sprite.width, btn.y / sprite.height};
    sfSprite_setScale(current->sprite, scale);
}

static void button_fabirc(data_t *data)
{
    button_t *current = data->buttons;

    while (current != NULL) {
        sfRectangleShape_setOutlineThickness(current->rect, current->bordure);
        sfRectangleShape_setOutlineColor(current->rect, sfBlack);
        sfRectangleShape_setSize(current->rect, current->size);
        sfRectangleShape_setPosition(current->rect, current->position);
        sfRectangleShape_setFillColor(current->rect, sfTransparent);
        if (my_strcmp(current->text_path, "NULL") != 0) {
            sprite_create(current);
        } else {
            current->sprite = NULL;
        }
        current = current->next;
    }
}

int buttons_starter(data_t *data)
{
    FILE *fp = fopen("config_files/paint.conf", "r");
    char *line = NULL;
    size_t len = 0;

    if (fp == NULL) {
        write(1, "ERROR : paint.conf not found, please contact me\n", 49);
        return 84;
    }
    while (getline(&line, &len, fp) != -1)
        if (line[0] != '#') {
            add_chained_list(data, line);
        }
    button_fabirc(data);
    fclose(fp);
    return 0;
}
