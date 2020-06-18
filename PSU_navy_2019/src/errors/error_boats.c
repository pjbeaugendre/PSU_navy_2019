/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** error_boats
*/

#include "struct.h"
#include "functions.h"
#include "my.h"

int error_char_file(char **arr)
{
    for (int i = 0; arr[i]; i++) {
        for (int j = 0; arr[i][j]; j++) {
            if ((arr[i][j] < '1' || arr[i][j] > '8')
            && (arr[i][j] < 'A' || arr[i][j] > 'H') && arr[i][j] != ':') {
                my_pstrerr("Invalid Chara of Pos\n");
                return (1);
            }
        }
    }
    if (arr[0][0] != '2' || arr[1][0] != '3'
    || arr[2][0] != '4' || arr[3][0] != '5') {
        my_pstrerr("Invalid Size of Boat\n");
        return (1);
    }
    return (0);
}

int error_size_file(char **arr)
{
    int size = 0;

    for (int i = 0; arr[i]; i++) {
        size = my_strlen(arr[i]);
        if (size != 7) {
            my_pstrerr("Invalid Size of Line\n");
            return (1);
        }
    }
    for (int i = 0; arr[i]; i++) {
        if (arr[i][2] != arr[i][5] && arr[i][3] != arr[i][6]) {
            my_pstrerr("Invalid Pos of Boat\n");
            return (1);
        }
    }
    return (0);
}

int error_number(char *line)
{
    int size = line[0] - '0';
    int nb1 = line[3] - '0';
    int nb2 = line[6] - '0';
    int res = (nb2 - nb1) + 1;

    if (size != res) {
        my_pstrerr("Impossible Boat Creation (Number)\n");
        return (1);
    } else
        return (0);
    return (0);
}

int error_letter(char *line)
{
    int size = line[0] - '0';
    int nb1 = line[2] - '0';
    int nb2 = line[5] - '0';
    int res = (nb2 - nb1) + 1;

    if (size != res) {
        my_pstrerr("Impossible Boat Creation (Letter)\n");
        return (1);
    } else
        return (0);
    return (0);
}