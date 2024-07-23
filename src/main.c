/*
** EPITECH PROJECT, 2024
** zsh
** File description:
** main
*/

#include "commands.h"
#include "utils.h"
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

static void configure_io_buffers(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IOLBF, 0);
}

static void handle_signal(int signal)
{
    if (signal == SIGINT) {
        write(STDOUT_FILENO, "\n", 1);
        fflush(stdout);
    }
}

static void setup_signal_handler(void)
{
    struct sigaction sa;

    sa.sa_handler = handle_signal;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);
}

int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;

    env_config_t *env_config = init_env_config(env);
    configure_io_buffers();
    setup_signal_handler();
    while (1) {
        read_and_execute_command(env_config);
    }
    return 0;
}
