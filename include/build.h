/*
** EPITECH PROJECT, 2020
** B-PSU-402-LYN-4-1-ftrace-jeremy.braconnier
** File description:
** build.h
*/

#ifndef BUILD_H
    #define BUILD_H

    #include "self.h"
    #include "file.h"

    self_t *build(int, char **, char **);
    file_t *build_file(void);
    content_t *build_content(void);

#endif /* BUILD_H */