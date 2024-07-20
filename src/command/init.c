/*
** EPITECH PROJECT, 2024
** zsh
** File description:
** init
*/

#include "commands.h"

command_t *init_command(const char *name, char **args, int arg_count)
{
    command_t *command = malloc(sizeof(command_t));
    command_ops_t *builtin_ops = init_builtin_ops();
    command_ops_t *external_ops = init_external_ops();

    command->name = strdup(name);
    command->args = malloc((arg_count + 1) * sizeof(char *));
    for (int i = 0; i < arg_count; i++) {
        command->args[i] = strdup(args[i]);
    }
    command->args[arg_count] = NULL;
    command->arg_count = arg_count;
    if (strcmp(name, "cd") == 0 || strcmp(name, "exit") == 0) {
        command->type = BUILTIN;
        command->vtable = builtin_ops;
    } else {
        command->type = EXTERNAL;
        command->vtable = external_ops;
    }
    return command;
}

void free_command(command_t *command)
{
    free(command->name);
    for (int i = 0; i < command->arg_count; i++) {
        free(command->args[i]);
    }
    free(command->args);
}
