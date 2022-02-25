/*
** EPITECH PROJECT, 2020
** C / C++ PROJECT
** File description:
** file
*/

#include "file.h"
#include "phaseout.h"
#include "build.h"
#include "self.h"

size_t file_open(file_t *file, char *path)
{
    struct stat stats;

    file->fd = open(path, O_RDONLY);
    if (file->fd >= 0) {
        fstat(file->fd, &stats);
        file->dump = mmap(NULL, stats.st_size,
            PROT_READ, MAP_SHARED, file->fd, 0);
        if (file->dump != MAP_FAILED) {
            file->ehdr = (Elf64_Ehdr *) file->dump;
            return (True);
        }
        printf("[ KO ] mmap failed\n");
        return (False);
    }
    printf("[ KO ] open failed\n");
    return (False);
}

size_t file_getenv(self_t *self)
{
    char **tmp = NULL;
    size_t env_size = phase_llength(self->env, NULL);

    for (size_t i = 0; i < env_size; i++) {
        tmp = phase_split(self->env[i], '=', EMPTY, NULL);
        if (phase_equals(tmp[0], "PATH\0", EMPTY) == True) {
            self->env_path = tmp[1];
            return (True);
        }
        phase_ffree(tmp, NULL);
    }
    return (False);
}

size_t file_path(self_t *self)
{
    char *tmp = NULL;
    size_t found = file_getenv(self);
    char **splitted = NULL;

    if (found == True) {
        splitted = phase_split(self->env_path, ':', EMPTY, NULL);
        for (size_t i = 0; i < phase_llength(splitted, NULL); i++) {
            tmp = phase_append(splitted[i], "/\0", EMPTY);
            tmp = phase_append(tmp, self->path, EMPTY);
            if (access(tmp, O_RDONLY) == 0) {
                self->path = tmp;
                return (True);
            }
        }
    }
    return (False);
}

size_t file_get(self_t *self)
{
    file_t *file = build_file();
    content_t *content = build_content();

    file_path(self);
    if (file_open(file, self->path) == True) {
        if (check_elf(file) == False) {
            printf("File format not recognized\n");
            return (False);
        }
        data_set(file, self);
        close(file->fd);
        return (True);
    }
    return (False);
}