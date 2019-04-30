/*
** EPITECH PROJECT, 2019
** create_and_write_file.c
** File description:
** create a write in a file
*/

#include "file.h"

int create_write_file(char *filename, char *cont)
{
    int fd = create_file(filename);
    int error = write_file(fd, cont);

    if (error == -1)
        return (-1);
    return (fd);
}
