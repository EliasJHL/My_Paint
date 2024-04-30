/*
** EPITECH PROJECT, 2023
** Elias josué HAJJAR LLAUQUEN
** File description:
** project for epitech
*/

#include "../include/my.h"

void remove_last_line(data_t *data)
{
    lines_t *current = NULL;
    lines_t *previous = NULL;

    if (data->lines == NULL)
        return;
    current = data->lines;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    if (previous != NULL) {
        previous->next = NULL;
    } else {
        data->lines = NULL;
    }
    sfVertexArray_destroy(current->array);
    free(current);
}

void draw_lines(data_t *data, sfRenderWindow *window)
{
    lines_t *current = data->lines;

    while (current != NULL) {
        sfRenderWindow_drawVertexArray(window, current->array, NULL);
        current = current->next;
    }
}

lines_t *create_line(void)
{
    lines_t *line = malloc(sizeof(lines_t));

    line->array = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(line->array, sfLinesStrip);
    line->next = NULL;
    return line;
}

static void add_el_in_array(data_t *data, sfVector2f point)
{
    lines_t *current = NULL;
    sfColor custom = sfColor_fromRGB(data->color[0], data->color[1],
        data->color[2]);
    sfVertex vertex = {.position = point, .color = custom};
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(data->board);

    if (data->lines == NULL ||
        !sfFloatRect_contains(&bounds, point.x, point.y))
        return;
    current = data->lines;
    while (current->next != NULL)
        current = current->next;
    sfVertexArray_append(current->array, vertex);
}

void square_draw(sfVector2f point, data_t *data)
{
    int size = data->size;
    int x_d = point.x - (size / 2);
    int y_d = point.y - (size / 2);
    int x_f = point.x + (size / 2);
    int y_f = point.y + (size / 2);
    int n = 1;

    if (size == 1) {
        add_el_in_array(data, point);
        return;
    }
    for (int i = y_d; i < y_f; i += n)
        for (int j = x_d; j < x_f; j += n)
            add_el_in_array(data, (sfVector2f){j, i});
}

void add_next_line(data_t *data)
{
    lines_t *new_line = create_line();
    lines_t *current = NULL;

    if (data->lines == NULL) {
        data->lines = new_line;
    } else {
        current = data->lines;
        while (current->next != NULL)
            current = current->next;
        current->next = new_line;
    }
}
