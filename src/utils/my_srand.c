/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** my_srand
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

void my_srand(void)
{
    int fd = open("/dev/urandom", O_RDONLY);
    unsigned int seed;
    ssize_t n_read;

    if (fd == -1) {
        srand(84);
    } else {
        n_read = read(fd, &seed, sizeof(seed));
        if (n_read != sizeof(seed))
            srand(84);
        else
            srand(seed);
        close(fd);
    }
}
