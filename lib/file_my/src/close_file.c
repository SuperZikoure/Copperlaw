/*
** EPITECH PROJECT, 2019
** close_file.c
** File description:
** close a file
*/

#include "file.h"

int close_file(fileinf_t *dir)
{
    int error = close(dir->fd);

    if (error == -1)
        return (-1);
    free_fileinf(dir);
    return (SUCESS);
}
