void cd_home(void)
{
    char *home = getenv("HOME");

    if (home == NULL) {
        fprintf(stderr, "cd: No home directory\n");
        return;
    }
    if (chdir(home) != 0) {
        perror("cd");
    }
}