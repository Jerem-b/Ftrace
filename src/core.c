/*
** EPITECH PROJECT, 2020
** B-PSU-402-LYN-4-1-ftrace-jeremy.braconnier
** File description:
** core.c
*/

#include "phaseout.h"
#include "self.h"
#include "build.h"
#include "file.h"
#include "ftrace.h"
#include "help.h"

size_t core(self_t *self)
{
    if (self->help == True)
        return (help());
    if (file_get(self) == True)
        return (child(self->path));
    return (False);
}
