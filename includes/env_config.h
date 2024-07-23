/*
** EPITECH PROJECT, 2024
** myzsh [WSL : Ubuntu]
** File description:
** env_config
*/

#ifndef ENV_CONFIG_H_
    #define ENV_CONFIG_H_

/**
 * @brief Structure representing a command's environment configuration.
 */
typedef struct env_config_s {
    char **env;          /** The environment variables for the command. */
    int env_count;       /** The number of environment variables. */
} env_config_t;

/**
 * @brief Initialize the environment configuration.
 *
 * @param env The environment variables for the command.
 * @return A pointer to the initialized environment configuration.
 */
env_config_t *init_env_config(char **env);

/**
 * @brief Destroy the environment configuration.
 *
 * @param env_config The environment configuration to destroy.
 */
void destroy_env_config(env_config_t *env_config);

#endif /* !ENV_CONFIG_H_ */
