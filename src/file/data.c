/*
** EPITECH PROJECT, 2020
** B-PSU-402-LYN-4-1-ftrace-jeremy.braconnier
** File description:
** data.c
*/

#include "file.h"
#include "phaseout.h"
#include "ftrace.h"
#include "self.h"

size_t data_set(file_t *file, self_t *self)
{
    file->shdr = (Elf64_Shdr *) ((char *) file->dump + file->ehdr->e_shoff);
    file->sym = (Elf64_Sym *) ((char *) file->dump + file->shdr->sh_offset);
    file->tab = file->dump + file->shdr[file->ehdr->e_shstrndx].sh_offset;
    strtab_get(file);
    sym_get(file);
    function_names_display(file, self);
    return (True);
}