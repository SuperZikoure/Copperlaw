/*
** EPITECH PROJECT, 2019
** free_fileinf.c
** File description:
** free struct fileinf_t
*/

#include "file.h"

void free_fileinf(fileinf_t *dir)
{
    if (dir->cont != NULL)
        free(dir->cont);
    if (dir->st != NULL)
        free(dir->st);
    if (dir != NULL)
        free(dir);
}
