/*
** EPITECH PROJECT, 2020
** C / C++ PROJECT
** File description:
** file
*/

#ifndef FILE_H
    #define FILE_H

    #include <sys/mman.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdint.h>
    #include <elf.h>
    #include "string.h"

    #include "phaseout.h"
    #include "self.h"

    typedef struct file_s
    {
        int fd;
        void *dump;
        Elf64_Ehdr *ehdr;
        Elf64_Shdr *shdr;
        Elf64_Sym *sym;
        char *tab;
        char *strtab;
    } file_t;

    typedef struct content_s
    {
        int address;
        char character;
        char *name;

        struct content_s *next;
    } content_t;

    size_t file_getenv(self_t *);
    size_t file_path(self_t *);
    size_t file_open(file_t *, char *);
    size_t file_get(self_t *);

    // ELF
    size_t check_elf(file_t *);
    size_t data_set(file_t *, self_t *);

    // TAB
    size_t strtab_get(file_t *);

    // SYM
    size_t sym_get(file_t *);

    //Function name
    void function_names_display(file_t *, self_t *);

    //Syscall name
    void syscall_names_display(file_t *, self_t *);
#endif /* FILE_H */