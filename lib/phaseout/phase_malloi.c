/*
** EPITECH PROJECT, 2020
** phaseout
** File description:
** phase_malloi.c
*/

#include "phaseout.h"

size_t *phase_malloi(size_t size, size_t c)
{
    size_t *target = NULL;

    target = malloc(sizeof(size_t) * (size + 1));
    if (target == 0) {
        for (size_t i = 0; i <= size; i++)
            target[i] = c;
        return (target);
    } else
        return (NULL);
}
