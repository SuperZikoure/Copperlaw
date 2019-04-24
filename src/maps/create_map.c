/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** create_map.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_rpg.h"
#include "graph.h"
#include "my_string.h"
#include "my_stdio.h"

static char *get_from_file(char *filepath)
{
    int n_read = -1;
    int buffer_size = 100000;
    char buffer[buffer_size + 1];
    int file = open(filepath, O_RDONLY);

    n_read = read(file, buffer, buffer_size);
    if (n_read == -1) {
        my_dprintf(2, "La map %s marche pas.\n", filepath);
        return (NULL);
    }
    buffer[n_read] = '\0';
    close(file);
    return (my_strdup(buffer));
}

map_t *create_map(char *filepath, window_t *window)
{
    map_t *map = malloc(sizeof(map_t));

    map->map = my_str_towordarray(get_from_file(filepath), "\n");
    if (map->map[0])
        map->size.x = my_strlen(map->map[0]);
    map->size.y = my_strarraylen(map->map);
    map->bg = create_image(my_strcat_no_free(filepath, "_bg.png"), window);
    map->fg = create_image(my_strcat_no_free(filepath, "_fg.png"), window);
    return (map);
}