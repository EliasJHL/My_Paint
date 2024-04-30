/*
** EPITECH PROJECT, 2023
** Elias josué HAJJAR LLAUQUEN
** File description:
** test 
*/

#include <unistd.h>

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

int my_putstr(char *str)
{
    write(1, str, my_strlen(str));
    return 0;
}