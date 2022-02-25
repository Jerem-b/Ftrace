/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-paul.gardien
** File description:
** phase_contains.c
*/

#include "phaseout.h"

size_t phase_contains(char *file, char c, char end)
{
    if (phase_count(file, c, end) >= 1)
        return (True);
    return (False);
}
