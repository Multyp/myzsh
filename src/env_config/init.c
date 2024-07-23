#include "env_config.h"
#include <stdlib.h>
#include <string.h>

env_config_t *init_env_config(char **env)
{
    env_config_t *env_config = malloc(sizeof(env_config_t));
    int env_count = 0;

    for (env_count = 0; env[env_count] != NULL; env_count++);
    env_config->env = malloc((env_count + 1) * sizeof(char *));
    for (int i = 0; i < env_count; i++) {
        env_config->env[i] = strdup(env[i]);
    }
    env_config->env[env_count] = NULL;
    env_config->env_count = env_count;
    return env_config;
}
