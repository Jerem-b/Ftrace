/*
** EPITECH PROJECT, 2020
** B-PSU-402-LYN-4-1-ftrace-jeremy.braconnier
** File description:
** build.c
*/

#include "phaseout.h"
#include "self.h"
#include "file.h"
#include "build.h"

self_t *build(int ac, char **argv, char **env)
{
    self_t *self = malloc(sizeof(self_t));

    self->help = False;
    self->path = NULL;
    self->ac = ac;
    self->argv = argv;
    self->env = env;
    self->env_path = NULL;
    return (self);
}

file_t *build_file(void)
{
    file_t *file = malloc(sizeof(file_t));

    file->fd = 0;
    file->ehdr = NULL;
    file->shdr = NULL;
    file->sym = NULL;
    file->strtab = NULL;
    return (file);
}

content_t *build_content(void)
{
    content_t *content = malloc(sizeof(content_t));

    content->address = 0;
    content->character = EMPTY;
    content->name = NULL;
    content->next = NULL;
    return (content);
}
