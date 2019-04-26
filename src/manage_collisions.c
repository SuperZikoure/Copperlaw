/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** manage_collisions.c
*/

#include <stdlib.h>
#include <math.h>
#include "graph.h"
#include "macros.h"
#include "my_rpg.h"

static int get_pos(int pos)
{
    int value = 0;

    value = pos - (pos % CELL_SIZE);
    value /= CELL_SIZE;
    return (value);
}

#include <stdio.h>

static void move_h(col_t *col, int current_map)
{
    int count = 0;
    int x = get_pos(col->pos->x + col->hitbox.x);
    int y = get_pos(col->pos->y + col->hitbox.y);

    for (int i = x - 1; i > 0; i--) {
        if (col->maps[current_map]->map[y][i] == '1') {
            count += (int) (col->pos->x + col->hitbox.x) % CELL_SIZE;
            break;
        }
        count += CELL_SIZE;
    }
    col->max[LEFT] = count - col->hitbox.z;
    count = 0;
    for (int i = x + 1; i < col->maps[current_map]->size.x; i++) {
        if (col->maps[current_map]->map[y][i] == '1') {
            count += CELL_SIZE - ((int) (col->pos->x + col->hitbox.x) % CELL_SIZE);
            break;
        }
        count += CELL_SIZE;
    }
    col->max[RIGHT] = count - col->hitbox.z;
}

static void move_v(col_t *col, int current_map)
{
    int count = 0;
    int x = get_pos(col->pos->x + col->hitbox.x);
    int y = get_pos(col->pos->y + col->hitbox.y);

    for (int i = box[0].y; i > 0; i--) {
        if (i == 1 || col->maps[current_map]->map[i][box[0].x] == '1' ||
        col->maps[current_map]->map[i][box[1].x] == '1') {
            count += ABS((int) col->hitbox.y % CELL_SIZE);
            break;
        }
        count += CELL_SIZE;
    }
    col->max[UP] = count - col->hitbox.z;
    count = 0;
    for (int i = box[1].y; i < col->maps[current_map]->size.y; i++) {
        if (i == 1 || col->maps[current_map]->map[i][box[0].x + 1] == '1' ||
        col->maps[current_map]->map[i][box[1].x] == '1') {
            count -= ABS((int) col->hitbox.y % CELL_SIZE);
            break;
        }
        count += CELL_SIZE;
    }
    col->max[DOWN] = count - col->hitbox.z;
}

void compute_col(col_t *col, int current_map, sfRectangleShape *rect)
{
    col->save.x = col->pos->x;
    col->save.y = col->pos->y;
    (void) current_map;
    // sfVector2i box[2];

    // box[0].x = get_pos(col->pos->x + col->hitbox.x);
    // box[0].y = get_pos(col->pos->y + col->hitbox.y);
    // box[1].x = get_pos(col->pos->x + col->hitbox.x + col->hitbox.z);
    // box[1].y = get_pos(col->pos->y + col->hitbox.y + col->hitbox.z);
    move_h(col, current_map);
    move_v(col, current_map);
    sfRectangleShape_setPosition(rect, V2F(col->hitbox.x + col->pos->x, col->hitbox.y + col->pos->y));
}
