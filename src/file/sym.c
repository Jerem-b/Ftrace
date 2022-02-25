/*
** EPITECH PROJECT, 2020
** B-PSU-402-LYN-4-1-ftrace-jeremy.braconnier
** File description:
** sym.c
*/

#include "file.h"
#include "phaseout.h"

size_t sym_get(file_t *file)
{
    size_t has_symbol = False;

    for (int i = 1; i < file->ehdr->e_shnum; i++) {
        if (file->shdr[i].sh_type == SHT_SYMTAB) {
            file->sym = (Elf64_Sym *)((char *)file->dump +
                file->shdr[i].sh_offset);
            has_symbol = True;
        }
    }
    if (has_symbol == False)
        printf("No symbol\n");
    return (True);
}