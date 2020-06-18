/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** file_error
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "struct.h"
#include "functions.h"
#include "my.h"

char *get_arr_filepath(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int rd = 0;
    char str[3000];
    char *str2 = NULL;

    if (fd == -1) {
        return (NULL);
    }
    rd = read(fd, str, 50);
    if (rd <= 0) {
        my_pstrerr("Error Read\n");
        return (NULL);
    }
    str[rd] = '\0';
    str2 = my_strdup(str);
    close(fd);
    return (str2);
}

int error_nb_boats(char **arr)
{
    int i = 0;

    for (; arr[i]; i++);
    if (i != 4) {
        my_pstrerr("Number of the boat is not 4\n");
        return (1);
    }
    return (0);
}

int error_pos_boat(char **arr)
{
    for (int i = 0; arr[i]; i++) {
        if (arr[i][2] == arr[i][5])
            if (error_number(arr[i]))
                return (84);
        if (arr[i][3] == arr[i][6])
            if (error_letter(arr[i]))
                return (84);
    }
    return (0);
}

int error_in_file(char *filepath)
{
    char *str = get_arr_filepath(filepath);
    char **arr = NULL;

    if (str == NULL)
        return (84);
    arr = my_str_to_word_array(str, "\n");
    if (error_nb_boats(arr) || error_char_file(arr) || error_size_file(arr)
    || error_pos_boat(arr))
        return (84);
    my_free_array(arr);
    return (0);
}