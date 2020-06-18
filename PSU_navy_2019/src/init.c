/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** init
*/

#include "functions.h"
#include "my.h"

char **init_points_map(void)
{
    char **arr = NULL;
    int i = 0;
    int j = 0;

    arr = malloc(sizeof(char *) * 9);
    for (; i < 8; i++) {
        arr[i] = malloc(sizeof(char) * 9);
        for (j = 0; j < 8; j++)
            arr[i][j] = '.';
        arr[i][j] = '\0';
    }
    arr[i] = NULL;
    return (arr);
}

void edit_p1_1(char **player1, char *str)
{
    int width = str[2] - '0' - 17;
    int start = str[3] - '0' - 1;
    int end = str[6] - '0';

    for (; start < end; start++)
        player1[start][width] = str[0];
}

void edit_p1_2(char **player1, char *str)
{
    int height = str[3] - '0' - 1;
    int start = str[2] - '0' - 17;
    int end = str[5] - '0' - 17;

    for (; start <= end; start++)
        player1[height][start] = str[0];
}

void edit_player1_map(char **arr)
{
    int i = 0;

    for (; arr[i]; i++) {
        if (arr[i][2] == arr[i][5])
            edit_p1_1(info.player1, arr[i]);
        else if (arr[i][3] == arr[i][6])
            edit_p1_2(info.player1, arr[i]);
    }
}

void init_player1(char *filepath)
{
    char *str = get_arr_filepath(filepath);
    char **arr = NULL;

    arr = my_str_to_word_array(str, "\n");
    info.end = 1;
    info.player1 = init_points_map();
    edit_player1_map(arr);
    info.player2 = init_points_map();
}