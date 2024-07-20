/*
** EPITECH PROJECT, 2024
** zsh
** File description:
** exec
*/

#include "commands.h"
#include <unistd.h>

void execute_builtin(command_t *command)
{
    if (strcmp(command->name, "cd") == 0) {
        if (command->arg_count < 2) {
            fprintf(stderr, "cd: missing argument\n");
        } else {
            if (chdir(command->args[1]) != 0) {
                perror("cd");
            }
        }
    } else if (strcmp(command->name, "exit") == 0) {
        exit(0);
    } else {
        fprintf(stderr, "%s: command not found\n", command->name);
    }
}
