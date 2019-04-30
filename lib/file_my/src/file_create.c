/*
** EPITECH PROJECT, 2019
** file_create.c
** File description:
** create a file
*/

#include "file.h"

int create_file(char *filename)
{
    int fd = open(filename, O_CREAT | O_RDWR, 777);

    return (fd);
}
