/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** navy
*/

#include "functions.h"
#include "my.h"

int check_winner2(void)
{
    int x = 0;

    for (int i = 0; info.player2[i]; i++) {
        for (int j = 0; info.player2[i][j]; j++)
            if (info.player2[i][j] == 'x')
                x++;
    }
    if (x == 14) {
        my_putstr("my positions:\n");
        display_map(info.player1);
        my_putstr("\nenemy's positions:\n");
        display_map(info.player2);
        my_putchar('\n');
        my_putstr("I won\n");
        info.end = 0;
        return (1);
    }
    return (0);
}

int check_winner(void)
{
    int x = 0;

    for (int i = 0; info.player1[i]; i++) {
        for (int j = 0; info.player1[i][j]; j++)
            if (info.player1[i][j] == 'x')
                x++;
    }
    if (x == 14) {
        my_putstr("my positions:\n");
        display_map(info.player1);
        my_putstr("\nenemy's positions:\n");
        display_map(info.player2);
        my_putchar('\n');
        my_putstr("Enemy won\n");
        info.end = 0;
        return (1);
    }
    if (check_winner2())
        return (1);
    return (0);
}

int game_loop(int ac)
{
    while(info.end) {
        if (ac == 2)
            play_player1();
        if (ac == 3)
            play_player2();
    }
    return (0);
}

int navy(int ac, char **av)
{
    int pid2 = 0;

    if (ac == 2) {
        if (error_in_file(av[1]) == 84)
            return (84);
        init_player1(av[1]);
        connect_player1();
    } else if (ac == 3) {
        if (error_in_file(av[2]) == 84)
            return (84);
        init_player1(av[2]);
        pid2 = my_getnbr(av[1]);
        connect_player2(pid2);
    }
    return (game_loop(ac));
}