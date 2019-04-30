/*
** EPITECH PROJECT, 2019
** create_save.c
** File description:
** create a file save.rpgs
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "load_save.h"

int create_save(STRUCT_GAME)
{
    int error = 0;
    int fd = 0;

    if (access("save.rpgs", F_OK) == -1) {
        fd = open("save.rpgs", O_CREAT | O_WRONLY | O_TRUNC);
        error = write_save(fd, STRUCT_GAME);
        close(fd);
        return (0);
    }
    else {
        open("save.rpgs", O_WRONLY | O_TRUNC);
        error = write_save(fd, STRUCT_GAME);
        close(fd);
    }
    return (-1);
}
