/*
** EPITECH PROJECT, 2024
** zsh
** File description:
** handle_loop
*/

#include "commands.h"
#include "utils.h"
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>


char **tokenize_input(char *line, int *arg_count)
{
    char **args = NULL;
    char *token = strtok(line, " ");

    *arg_count = 0;
    while (token != NULL) {
        args = realloc(args, (*arg_count + 1) * sizeof(char *));
        if (!args) {
            perror("Failed to realloc memory");
            exit(EXIT_FAILURE);
        }
        args[*arg_count] = token;
        (*arg_count)++;
        token = strtok(NULL, " ");
    }
    return args;
}

int read_input(char *line)
{
    display_prompt();
    if (fgets(line, BUFFER_SIZE, stdin) == NULL) {
        return feof(stdin) ? -1 : 0;
    }
    line[strcspn(line, "\n")] = '\0';
    return 1;
}

void execute_command(char **args, int arg_count)
{
    command_t *command = init_command(args[0], args, arg_count);

    command->vtable->execute(command);
    free_command(command);
}

void read_and_execute_command(env_config_t *env_config)
{
    char line[BUFFER_SIZE];
    char **args;
    int arg_count;
    int status = read_input(line);
    (void)env_config;

    if (status == -1) {
        exit(0);
    } else if (status == 0) {
        return;
    }
    args = tokenize_input(line, &arg_count);
    if (arg_count == 0) {
        free(args);
        return;
    }
    execute_command(args, arg_count);
    free(args);
}
