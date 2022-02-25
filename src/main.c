/*
** EPITECH PROJECT, 2020
** B-PSU-402-LYN-4-1-ftrace-jeremy.braconnier
** File description:
** main.c
*/

#include "phaseout.h"
#include "self.h"
#include "build.h"
#include "ftrace.h"

size_t arguments(self_t *self)
{
    if (self->ac == 2) {
        if (phase_equals(self->argv[1], "--help\0", EMPTY) == True)
            self->help = True;
        self->path = self->argv[1];
        return (True);
    }
    return (False);
}

int main(int ac, char **argv, char **env)
{
    self_t *self = build(ac, argv, env);

    if (arguments(self) == True) {
        printf("Entering function main at %p\n", &main);
        return (core(self));
    }
    return (84);
}
