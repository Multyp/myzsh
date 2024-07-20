/*
** EPITECH PROJECT, 2024
** zsh
** File description:
** exec
*/

#include "commands.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void execute_external(command_t *command)
{
    pid_t pid = fork();
    int status;

    switch (pid) {
        case -1:
            perror("fork");
            break;
        case 0:
            execvp(command->name, command->args);
            perror("execvp");
            exit(EXIT_FAILURE);
            break;
        default:
            waitpid(pid, &status, 0);
            break;
    }
}
