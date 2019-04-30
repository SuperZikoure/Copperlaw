/*
** EPITECH PROJECT, 2019
** free_dirinf.c
** File description:
** free struct dirinf_t
*/

#include "file.h"

void free_dirinf(dirinf_t *dir)
{
    if (dir->flux != NULL)
        free(dir->flux);
    if (dir->dirent != NULL)
        free(dir->dirent);
    if (dir != NULL)
        free(dir);
}
