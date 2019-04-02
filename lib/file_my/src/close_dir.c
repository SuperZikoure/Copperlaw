/*
** EPITECH PROJECT, 2019
** close_dir.h
** File description:
** close a dir
*/

#include "file.h"

int close_dir(dirinf_t *dir)
{
    int error = closedir(dir->flux);

    if (error == -1)
        return (-1);
    free_dirinf(dir);
    return (SUCESS);
}
