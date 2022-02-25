/*
** EPITECH PROJECT, 2020
** B-PSU-402-LYN-4-1-ftrace-jeremy.braconnier
** File description:
** self.h
*/

#ifndef SELF_H
    #define SELF_H

    #include "phaseout.h"

    typedef struct self_s
    {
        size_t help;
        char *path;

        int ac;
        char **argv;
        char **env;
        char *env_path;
    } self_t;

#endif /* SELF_H */