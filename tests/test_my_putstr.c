/*
** EPITECH PROJECT, 2023
** Elias josué HAJJAR LLAUQUEN
** File description:
** test 
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_putstr, should_print_string_to_stdout, .init = redirect_all_std)
{
    my_putstr("Hello, World!");
    cr_assert_stdout_eq_str("Hello, World!");
}