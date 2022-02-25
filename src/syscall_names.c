/*
** EPITECH PROJECT, 2020
** B-PSU-402-LYN-4-1-ftrace-jeremy.braconnier
** File description:
** syscall_names.c
*/

#include "ftrace.h"
#include "self.h"
#include "file.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void trace_child(pid_t pid, self_t *self)
{
    if (pid == 0) {
        ptrace(PTRACE_TRACEME, 0, 0, 0);
        execvp(self->argv[1], self->argv + 1);
    }
}

int check_signal(siginfo_t signal, pid_t pid)
{
    ptrace(PTRACE_GETSIGINFO, pid, 0, &signal);
    if (signal.si_signo >= 1 && signal.si_signo <= 30 && signal.si_signo != 5){
        printf("Received signal %s\n", signal_tab[signal.si_signo]);
        return 1;
    }
    return 0;
}

void display_syscall(int nb_args, struct user_regs_struct regs)
{
    long long int regs_tab[6] = {regs.rdi, regs.rsi,
        regs.rdx, regs.r10, regs.r8, regs.r9};

    printf("Syscall %s(", sysname_tab[regs.orig_rax]);
    for (int i = 0; i < nb_args - 1; i++) {
        printf("%p, ", regs_tab[i]);
    }
    printf("%p) = ", regs_tab[nb_args - 1]);
    (sysret_tab[regs.orig_rax] == 1) ? printf("?\n") : printf("%p\n",
    regs.rax);
}

void syscall_names_display(file_t *file, self_t *self)
{
    pid_t pid = fork();
    int status, in_call = 0;
    struct user_regs_struct regs;
    siginfo_t signal;

    trace_child(pid, self);
    wait(&status);
    while (status == 1407) {
        ptrace(PTRACE_GETREGS, pid, NULL, &regs);
        if (!in_call) {
            display_syscall(sysargs_tab[regs.orig_rax], regs);
            in_call = 1;
        }
        else
            in_call = 0;
        ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
        wait(&status);
        if (check_signal(signal, pid) == 1)
            break;
    }
}