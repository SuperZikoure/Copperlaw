/*
** EPITECH PROJECT, 2019
** init_stat.c
** File description:
** return a pointer to a struct stat of a file
*/

#include "file.h"

struct stat *init_stat(char *filepath)
{
    struct stat *statbuf = malloc(sizeof(struct stat));
    int error;

    if (statbuf == NULL)
        return (NULL);
    error = stat(filepath, statbuf);
    if (error == -1)
        my_putmod_str(2, "[file.h] ERROR : init_stat failed\n");
    return (statbuf);
}
