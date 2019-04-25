/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** manage_collisions.c
*/

#include <stdlib.h>
#include <math.h>
#include "graph.h"
#include "my_rpg.h"

int get_pos(int pos)
{
    int value = 0;

    value = pos - (pos % CELL_SIZE);
    vale /= CELL_SIZE;
    return (value);
}

void compute_col(col_t *col, int current_map)
{
    sfVector2i box[2];

    box[0].x = get_pos(col->pos->x + col->hitbox.left),;
    box[0].y = get_pos(col->pos->y + col->hitbox.top);
    box[1].x = get_pos(col->pos->x + col->hitbox.left + col->hitbox.width);
    box[1].y = get_pos(col->pos->y + col->hitbox.top + col->hitbox.height);
    col->max[UP] = 
}