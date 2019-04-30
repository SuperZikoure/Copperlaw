/*
** EPITECH PROJECT, 2019
** write_file.c
** File description:
** write in a file
*/

#include "file.h"

size_t write_file(int fd, char *cont)
{
    size_t error = write(fd, cont, my_strlen(cont));

    if (error == -1 || my_strlen(cont) == 0) {
        return (-1);
    }
    return (SUCESS);
}
