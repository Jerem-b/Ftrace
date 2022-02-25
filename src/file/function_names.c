/*
** EPITECH PROJECT, 2019
** B-PSU-402-LYN-4-1-ftrace-jeremy.braconnier
** File description:
** Created by flavien,
*/

#include "file.h"
#include "phaseout.h"
#include "ftrace.h"
#include "self.h"

char *manage_display_function(char *function, int len)
{
    char *result = (char *) malloc(sizeof(len));

    strcpy(result, function);
    for (int i = 0; i < len - 1 ; ++i) {
        if (function[i] == '@') {
            strcpy(result, function);
            result[i] = '\0';
            return result;
        }
    }
    return result;
}

int function_have_dot(char *function, int len)
{
    for (int i = 0; i < len - 1 ; ++i) {
        if (function[i] == '.' && (
            function[i + 1] == 'c' || function[i + 1] == '0') &&
            function[i + 2] == '\0')
            return 1;
        if (function[i] == '@')
            return 1;
    }
    if (function[0] == '.')
        return 1;
    return 0;
}

void function_can_be_displayed(char *function, file_t *fd, int mode, int j)
{
    int len = strlen(function);

    if (len < 2)
        return;
    if (function_have_dot(function, len) == 1)
        return;
    if (strncmp("_", function, 1) != 0 && strncmp("main", function, 4) != 0) {
        if (mode == 0) {
            printf("Entering function %s at 0x%lx\n", function,
                fd->sym[j].st_value);
        } else
            printf("Leaving function %s\n", function);
    }
}

void function_names_dp_init(file_t *fd, int mode)
{
    Elf64_Shdr *sh, *strtab;
    Elf64_Sym *sym;
    char *symmaddr, *function;
    Elf64_Shdr *head = (Elf64_Shdr *) ((char *) fd->ehdr + fd->ehdr->e_shoff);

    for (int i = 0; i < fd->ehdr->e_shnum; i++) {
        if (head[i].sh_type == SHT_SYMTAB) {
            sh = &head[i];
            symmaddr = (char *) fd->ehdr + (&head[i])->sh_offset;
            break;
        }
    }
    if (sh->sh_size == 0 || sh->sh_entsize == 0)
        return;
    for (int j = 0; j < ((int) (sh->sh_size / sh->sh_entsize)); j++) {
        sym = &((Elf64_Sym *) symmaddr)[j];
        strtab = &head[sh->sh_link];
        function = (char *) fd->ehdr + strtab->sh_offset + sym->st_name, head;
        function_can_be_displayed(function, fd, mode, j);
    }
}

void function_names_display(file_t *fd, self_t *self)
{
    function_names_dp_init(fd, 0);
    syscall_names_display(fd, self);
    function_names_dp_init(fd, 1);
}