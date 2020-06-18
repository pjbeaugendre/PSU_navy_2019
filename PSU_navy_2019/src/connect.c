/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** connect
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


static void handler(int signum, siginfo_t *siginfo, void *context)
{
    signum = signum;
    (void)context;
    info.pid_2 = siginfo->si_pid;
}

void wait_signal(void)
{
    struct sigaction sig;

    sig.sa_flags = SA_SIGINFO;
    sig.sa_sigaction = &handler;
    sigaction(SIGUSR1, &sig, NULL);
    pause();
}

void connect_player1(void)
{
    info.pid_1 = getpid();
    my_putstr("my pid: ");
    my_put_nbr(info.pid_1);
    my_putstr("\nwaiting for enemy connection...\n");
    wait_signal();
    my_putstr("\nenemy connected\n");
}

void connect_player2(pid_t pid)
{
    info.pid_1 = getpid();
    info.pid_2 = pid;
    my_putstr("my pid: ");
    my_put_nbr(info.pid_1);
    kill(info.pid_2, SIGUSR1);
    my_putstr("\nsuccessfully connected\n");
}