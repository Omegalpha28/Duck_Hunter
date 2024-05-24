/*
** EPITECH PROJECT, 2023
** MY_HUNTER
** File description:
** -h
*/
#include "my_hunter.h"
#include <unistd.h>

void my_help(void)
{
    my_putstr("USAGE\n     ./my_hunter map\nDESCRIPTION\n     we have to kill ");
    my_putstr("ducks unfortunately the developer had problems during ");
    my_putstr("the development of the game.\n");
}

int is_help(char **av)
{
    if (my_strcmp(av[1], "-h") == 0) {
        my_help();
        return 0;
    } else {
        write(2, "Too arguments!\n", 16);
        return 84;
    }
}
