/*
** EPITECH PROJECT, 2019
** is_dir.c
** File description:
** check if it's a file or a dir
*/

#include "file.h"

int is_dir(char *filepath)
{
    int fd = access(filepath, F_OK);

    if (fd == -1) {
        my_putmod_str(2, "[file.h] ERROR : file doesn't exist\n");
        return (FAILURE);
    }
    fd = open(filepath, O_DIRECTORY);
    if (fd == -1) {
        close(fd);
        return (0);
    }
    close(fd);
    return (1);
}
