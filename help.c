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
    my_putstr("USAGE\n     ./my_sokoban map\nDESCRIPTION\n     map  file ");
    my_putstr("representing the warehouse map, containing ‘#’ for walls,\n");
    my_putstr("          ");
    my_putstr("‘P’ for the player, ‘X’ for boxes and ‘O’ for storage ");
    my_putstr("locations.\n");
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