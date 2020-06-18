/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "struct.h"
#include "functions.h"

void display_usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    first_player_pid: only for the 2nd player. ");
    my_putstr("pid of the first player.\n");
    my_putstr("    navy_positions: file representing the positions ");
    my_putstr("of the ships.\n");
}

int main(int ac, char **av)
{
    if (ac < 2 || ac > 3)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        display_usage();
        return (0);
    }
    return (navy(ac, av));
}
