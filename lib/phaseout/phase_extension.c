/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-paul.gardien
** File description:
** phase_extension.c
*/

#include "phaseout.h"

size_t phase_extension(char *file, char *extension, char end)
{
    size_t result = Error;
    char **extensions = NULL;

    if (phase_contains(file, '.', end) == True) {
        extensions = phase_split(file, '.', end, NULL);
        result = phase_equals(
            extensions[phase_llength(extensions, NULL) - 1], extension, end);
        phase_ffree(extensions, NULL);
    }
    return (result);
}
