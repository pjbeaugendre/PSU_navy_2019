/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** functions
*/

#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include "struct.h"

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

info_t info;

int main(int ac, char **av);

int error_in_file(char *filepath);

char *get_arr_filepath(char *filepath);

int navy(int ac, char **av);

int error_letter(char *line);

int error_number(char *line);

int error_size_file(char **arr);

int error_char_file(char **arr);

void connect_player1(void);

void connect_player2(pid_t pid);

void init_player1(char *filepath);

void display_map(char **arr);

void play_player1(void);

void play_player2(void);

char *take_input(void);

int check_input(char *str);

void check_hit_or_not(void);

void check_hit(void);

void my_send(void);

void my_receive(void);

int check_winner(void);

int check_winner2(void);

#endif