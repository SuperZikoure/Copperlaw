/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** create_map.c
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my_string.h"

char **read_map_from_file(char *filepath);

map_t *create_map(char *filepath, window_t *window)
{
    sfColor color = (sfColor){255, 255, 255, 225};
    map_t *map = malloc(sizeof(map_t));

    if (!map)
        return NULL;
    map->map = read_map_from_file(filepath);
    if (!map->map)
        return NULL;
    if (map->map[0])
        map->size.x = my_strlen(map->map[0]);
    map->size.y = my_strarraylen(map->map);
    map->bg = create_image(my_strcat_no_free(filepath, "_bg.png"), window);
    map->fg = create_image(my_strcat_no_free(filepath, "_fg.png"), window);
    sfSprite_setColor(map->fg->sprite, color);
    if (!map->bg || !map->fg)
        return NULL;
    return (map);
}
