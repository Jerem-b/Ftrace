/*
** EPITECH PROJECT, 2020
** C / C++ PROJECT
** File description:
** file
*/

#include "file.h"
#include "phaseout.h"

size_t strtab_get(file_t *file)
{
    for (int i = 1; i < file->ehdr->e_shnum; i++) {
        if (file->shdr[i].sh_type == SHT_STRTAB) {
            file->strtab = (char *) ((char *) file->dump +
                file->shdr[i].sh_offset);
        }
    }
    return (True);
}