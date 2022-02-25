/*
** EPITECH PROJECT, 2020
** B-PSU-402-LYN-4-1-ftrace-jeremy.braconnier
** File description:
** ftrace.h
*/

#ifndef FTRACE_H
    #define FTRACE_H

    #include "phaseout.h"
    #include "self.h"
    #include <sys/ptrace.h>
    #include <sys/user.h> 
    #include "syscall_name.h"

    size_t arguments(self_t *);
    size_t core(self_t *);

    // CHILD
    size_t status(int);
    size_t launch(char *);
    size_t child(char *);
#endif /* FTRACE_H */