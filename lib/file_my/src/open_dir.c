/*
** EPITECH PROJECT, 2019
** open_dir.c
** File description:
** open a dir and return a DIR struct
*/

#include "file.h"

DIR *open_dir(char *filepath)
{
    DIR *flux = opendir(filepath);

    return (flux);
}
