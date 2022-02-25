/*
** EPITECH PROJECT, 2020
** C / C++ PROJECT
** File description:
** file
*/

#include "file.h"
#include "phaseout.h"
#include "ftrace.h"
#include "self.h"

size_t check_elf(file_t *file)
{
    if (file->ehdr->e_ident[EI_MAG0] != 0x7F ||
        file->ehdr->e_ident[EI_MAG1] != 'E' ||
        file->ehdr->e_ident[EI_MAG2] != 'L' ||
        file->ehdr->e_ident[EI_MAG3] != 'F') {
        return (False);
    }
    return (True);
}