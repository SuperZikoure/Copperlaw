/*
** EPITECH PROJECT, 2019
** init_fileinf.c
** File description:
** init a struct fileinf_t
*/

#include "file.h"

fileinf_t *init_fileinf(char *filepath)
{
    fileinf_t *dir = malloc(sizeof(fileinf_t));

    if (dir == NULL)
        my_putmod_str(2, "[file.h] ERROR : init_fileinf function failed\n");
    dir->fd = open_file(filepath);
    dir->cont = read_file(filepath);
    dir->st = init_stat(filepath);
    return (dir);
}
