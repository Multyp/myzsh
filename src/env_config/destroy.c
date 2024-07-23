#include "env_config.h"
#include <stdlib.h>

void destroy_env_config(env_config_t *env_config)
{
    for (int i = 0; i < env_config->env_count; i++) {
        free(env_config->env[i]);
    }
    free(env_config->env);
    free(env_config);
}