/*
** EPITECH PROJECT, 2019
** check_access.c
** File description:
** check the authorization of a file or a dir
*/

#include "file.h"

int check_access(char *filepath)
{
    int fd = access(filepath, F_OK);

    if (fd == -1)
        return (FAILURE);
    return (SUCESS);
}
