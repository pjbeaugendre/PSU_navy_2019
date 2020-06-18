/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

typedef struct info
{
    int pid_1;
    int pid_2;
    int end;
    int sig1;
    int sig2;
    int y_n;
    int hit_not;
    char *input_1;
    char *input_2;
    char **player1;
    char **player2;
    char **enemy1;
} info_t;

#endif
