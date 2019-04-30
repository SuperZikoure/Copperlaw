/*
** EPITECH PROJECT, 2019
** read_dir.c
** File description:
** return a pointer to a dirent struct
*/

#include "file.h"

struct dirent *read_dir(char *filepath)
{
    DIR *op_file = open_dir(filepath);
    struct dirent *dir = malloc(sizeof(struct dirent));

    if (op_file == NULL)
        return (NULL);
    dir = readdir(op_file);
    return (dir);
}
