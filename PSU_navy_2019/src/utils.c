/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** utils
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

void display_map(char **arr)
{
    int x = 1;

    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int i = 0; i < 8; i++, x++) {
        my_put_nbr(x);
        my_putstr("|");
        for (int j = 0; arr[i][j]; j++) {
            my_putchar(arr[i][j]);
            if (j < 8)
                my_putchar(' ');
        }
        my_putchar('\n');
    }
}

char *take_input(void)
{
    char *str = malloc(sizeof(char) * 50);
    int rd = 0;

    rd = read(0, str, 50);
    if (rd == -1)
        return ("\n");
    str[rd] = '\0';
    return (str);
}

int check_input(char *str)
{
    int size = my_strlen(str);

    if (size != 3) {
        my_putstr("wrong position\n");
        return (1);
    }
    if (str[0] < 'A' || str[0] > 'H') {
        my_putstr("wrong position\n");
        return (1);
    }
    if (str[1] < '1' || str[1] > '8') {
        my_putstr("wrong position\n");
        return (1);
    }
    return (0);
}