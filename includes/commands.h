/*
** EPITECH PROJECT, 2024
** zsh
** File description:
** commands
*/

#ifndef COMMANDS_H_
    #define COMMANDS_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "env_config.h"

    #define BUFFER_SIZE 1024

/**
 * @brief Enum representing the type of command.
 */
typedef enum {
    BUILTIN, /** Builtin command type. */
    EXTERNAL /** External command type. */
} command_type_t;

/**
 * @brief Structure representing a command.
 */
typedef struct command_s {
    command_type_t type; /** The type of the command (builtin or external). */
    char *name;          /** The name of the command. */
    char **args;         /** The arguments for the command. */
    int arg_count;       /** The number of arguments. */
    struct command_ops_s *vtable; /** Pointer to the vtable for polymorphism */
} command_t;

/**
 * @brief Structure representing the vtable for command operations.
 */
typedef struct command_ops_s {
    /** Function pointer for executing a command. */
    void (*execute)(command_t *command);
} command_ops_t;

/**
 * @brief Initialize the builtin command operations vtable.
 *
 * @return A pointer to the initialized builtin command operations vtable.
 */
command_ops_t *init_builtin_ops(void);

/**
 * @brief Initialize the external command operations vtable.
 *
 * @return A pointer to the initialized external command operations vtable.
 */
command_ops_t *init_external_ops(void);

/**
 * @brief Destroy the command operations vtable.
 *
 * @param vtable The command operations vtable to destroy.
 */
void destroy_command_ops(command_ops_t *vtable);

/**
 * @brief Execute a builtin command.
 *
 * @param command The command to execute.
 */
void execute_builtin(command_t *command);

/**
 * @brief Execute an external command.
 *
 * @param command The command to execute.
 */
void execute_external(command_t *command);

/**
 * @brief Initialize a command object.
 *
 * @param command The command object to initialize.
 * @param name The name of the command.
 * @param args The arguments for the command.
 * @param arg_count The number of arguments.
 */
command_t *init_command(const char *name, char **args, int arg_count);

/**
 * @brief Free a command object.
 *
 * @param command The command object to free.
 */
void free_command(command_t *command);

/**
 * @brief Read and execute a command.
 *
 * @param env_config The environment configuration for the command.
 */
void read_and_execute_command(env_config_t *env_config);

#endif /* !COMMANDS_H_ */
