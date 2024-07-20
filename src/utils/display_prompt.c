/*
** EPITECH PROJECT, 2024
** zsh
** File description:
** display_prompt
*/

#include "commands.h"
#include <unistd.h>

void display_prompt(void)
{
    char cwd[BUFFER_SIZE];

    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("\033[1;34m%s\033[0m \033[1;32m$ \033[0m", cwd);
    } else {
        perror("getcwd");
        printf("\033[1;32m$ \033[0m");
    }
    fflush(stdout);
}
