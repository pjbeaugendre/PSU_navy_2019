/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** send
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

static void handler3(int signum, siginfo_t *sig, void *context)
{
    int letter = info.input_1[0] - 'A';
    int number = info.input_1[1] - '0' - 1;
    sig = sig;
    (void)context;

    if (signum == SIGUSR1) {
        my_putchar(info.input_1[0]);
        my_putchar(info.input_1[1]);
        my_putstr(": hit\n\n");
        info.player2[number][letter] = 'x';
    }
    if (signum == SIGUSR2) {
        my_putchar(info.input_1[0]);
        my_putchar(info.input_1[1]);
        my_putstr(": missed\n\n");
        if (info.player2[number][letter] == 'x')
            info.player2[number][letter] = 'x';
        else
            info.player2[number][letter] = 'o';
    }
}

void my_send(void)
{
    int letter = info.input_1[0] - 'A' + 1;
    int number = info.input_1[1] - '0';

    for (int i = 0; i < letter; i++) {
        usleep(310);
        kill(info.pid_2, SIGUSR1);
    }
    for (int i = 0; i < number; i++) {
        usleep(310);
        kill(info.pid_2, SIGUSR2);
    }
    usleep(310);
    kill(info.pid_2, SIGUSR1);
}

void check_hit_or_not(void)
{
    struct sigaction sig;

    sig.sa_sigaction = &handler3;
    sig.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sig, NULL);
    sigaction(SIGUSR2, &sig, NULL);
}