/*
** EPITECH PROJECT, 2019
** read_file.c
** File description:
** return a buffer filled with the readed file
*/

#include "file.h"

char *read_file(char *filepath)
{
    int fd = open_file(filepath);
    struct stat *st = init_stat(filepath);
    char *buf;
    int error;

    if (st == NULL)
        return (NULL);
    buf = malloc(sizeof(char) * st->st_size + 1);
    buf[st->st_size] = '\0';
    error = read(fd, buf, st->st_size);
    if (error == -1)
        return (NULL);
    return (buf);
}
