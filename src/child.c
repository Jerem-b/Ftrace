/*
** EPITECH PROJECT, 2020
** C / C++ PROJECT
** File description:
** file
*/

#include "phaseout.h"
#include "build.h"
#include "ftrace.h"

size_t status(int status_value)
{
    if (wait(&status_value) != -1) {
        if (WIFEXITED(status_value)) {
            printf("Leaving function main\n");
            printf("+++ exited with %d +++\n", status_value);
        }
        if (WIFSIGNALED(status_value))
            printf("+++ kill by %d +++\n", WTERMSIG(status_value));
        return (True);
    }
    return (False);
}

size_t launch(char *path)
{
    int status_value = 0;
    char *launcher[] = {path, NULL};
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return (False);
    } else if (pid == 0)
        execvp(path, launcher);
    else
        status(status_value);
    return (True);
}

size_t child(char *path)
{
    return (launch(path));
}
