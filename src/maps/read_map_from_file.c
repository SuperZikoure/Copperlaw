/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** read_map_from_file
*/

#include <stdlib.h>
#include "utils.h"

const unsigned int linepack = 500;

static char **realloc_map(char **map, unsigned int line_nb, size_t newlines)
{
    char **newmap = malloc(sizeof(char *) * (line_nb + newlines));

    if (!newmap)
        return NULL;
    for (size_t i = 0; i < line_nb; i++)
        newmap[i] = map[i];
    return newmap;
}

char **read_map_from_file(char *filepath)
{
    char *newline;
    size_t maxlines = linepack;
    unsigned int lines = 0;
    char **map = malloc(sizeof(char *) * maxlines);
    FILE *f_stream = fopen(filepath, "r");

    if (!map || !f_stream)
        return NULL;
    newline = get_line(f_stream);
    while (newline) {
        if (lines == maxlines) {
            map = realloc_map(map, lines, linepack);
            maxlines += linepack;
        }
        map[lines++] = newline;
        newline = get_line(f_stream);
    }
    map[lines] = NULL;
    return map;
}
