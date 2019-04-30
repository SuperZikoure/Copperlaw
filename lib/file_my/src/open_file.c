/*
** EPITECH PROJECT, 2019
** open_file.c
** File description:
** open a file and return fd
*/

#include "file.h"

int open_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int error = (fd == -1) ? FAILURE : fd;

    return (error);
}
