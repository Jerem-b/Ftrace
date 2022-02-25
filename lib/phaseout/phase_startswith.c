/*
** EPITECH PROJECT, 2020
** B-PSU-400-LYN-4-1-nmobjdump-paul.gardien
** File description:
** phase_startswith.c
*/

#include "phaseout.h"

size_t phase_startswith(char *original, char *check, char end)
{
    size_t size = phase_length(original, end);
    size_t check_size = phase_length(check, end);

    if (size >= check_size) {
        for (size_t i = 0; i < check_size; i++) {
            if (original[i] != check[i]) {
                return (False);
            }
        }
        return (True);
    }
    return (False);
}
