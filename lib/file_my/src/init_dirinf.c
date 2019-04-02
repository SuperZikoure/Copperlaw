/*
** EPITECH PROJECT, 2019
** init_dirinf.c
** File description:
** init a struct dirinf_t
*/

#include "file.h"

dirinf_t *init_dirinf(char *filepath)
{
    dirinf_t *dir = malloc(sizeof(dirinf_t));

    dir->flux = open_dir(filepath);
    dir->dirent = read_dir(filepath);
    return (dir);
}
