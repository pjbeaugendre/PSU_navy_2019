/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** play2
*/

#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include "struct.h"
#include "functions.h"
#include "my.h"

void play_player2_2(void)
{
    do {
        my_putstr("attack: ");
        info.input_1 = take_input();
    } while (check_input(info.input_1));
    my_send();
    check_hit_or_not();
    usleep(310);
}

void play_player2(void)
{
    my_putstr("\nmy positions:\n");
    display_map(info.player1);
    my_putstr("\nenemy's position:\n");
    display_map(info.player2);
    my_putstr("\nwaiting for enemy's attack...\n");
    my_receive();
    check_hit();
    my_putchar(info.sig1 + 'A');
    my_putchar(info.sig2 + '0' + 1);
    if (info.hit_not)
        my_putstr(": hit\n\n");
    else if (info.hit_not == 0)
        my_putstr(": missed\n\n");
    if (check_winner())
        return;
    play_player2_2();
    if (check_winner())
        return;
}