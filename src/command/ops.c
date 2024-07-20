/*
** EPITECH PROJECT, 2024
** zsh
** File description:
** ops
*/

#include "commands.h"

command_ops_t *init_builtin_ops(void)
{
    command_ops_t *ops = malloc(sizeof(command_ops_t));

    if (ops) {
        ops->execute = execute_builtin;
    }
    return ops;
}

command_ops_t *init_external_ops(void)
{
    command_ops_t *ops = malloc(sizeof(command_ops_t));

    if (ops) {
        ops->execute = execute_external;
    }
    return ops;
}

void destroy_command_ops(command_ops_t *vtable)
{
    free(vtable);
}
