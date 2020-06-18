/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** receive
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

static void handler2(int signum, siginfo_t *siginfo, void *context)
{
    siginfo = siginfo;
    (void)context;
    if (info.sig2 != 0 && signum == SIGUSR1)
        info.y_n = 0;
    if (signum == SIGUSR1)
        info.sig1++;
    if (signum == SIGUSR2)
        info.sig2++;
}

void my_receive(void)
{
    struct sigaction sig;

    sig.sa_sigaction = &handler2;
    sig.sa_flags = SA_SIGINFO;
    info.sig1 = 0;
    info.sig2 = 0;
    info.y_n = 1;
    while (info.y_n) {
        sigaction(SIGUSR1, &sig, NULL);
        sigaction(SIGUSR2, &sig, NULL);
        usleep(260);
    }
    info.sig1 -= 2;
    info.sig2--;
}

void check_hit(void)
{
    if ((info.player1[info.sig2][info.sig1] < '2'
    || info.player1[info.sig2][info.sig1] > '5')) {
        if (info.player1[info.sig2][info.sig1] == 'x')
            info.player1[info.sig2][info.sig1] = 'x';
        else
            info.player1[info.sig2][info.sig1] = 'o';
        kill(info.pid_2, SIGUSR2);
        info.hit_not = 0;
    } else {
        info.player1[info.sig2][info.sig1] = 'x';
        kill(info.pid_2, SIGUSR1);
        info.hit_not = 1;
    }
}