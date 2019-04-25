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

static int get_pos(int pos)
{
    int value = 0;

    value = pos - (pos % CELL_SIZE);
    value /= CELL_SIZE;
    return (value);
}

static void move_h(col_t *col, int current_map, sfVector2i box[2])
{
    int count = 0;

    for (int i = box[0].x; i > 0; i--) {
        if (i == 1 || col->maps[current_map]->map[box[0].y][i] == '1' ||
col->maps[current_map]->map[box[1].y][i] == '1') {
            count += ABS((int)col->pos->x % CELL_SIZE);
            break;
        }
        count += CELL_SIZE;
    }
    col->max[LEFT] = count - 8;
    count = 0;
    for (int i = box[1].x; i < col->maps[current_map]->size.x; i++) {
        if (i == 1 || col->maps[current_map]->map[box[0].y][i] == '1' ||
col->maps[current_map]->map[box[1].y][i] == '1') {
            count -= ABS((int)col->pos->x % CELL_SIZE);
            break;
        }
        count += CELL_SIZE;
    }
    col->max[RIGHT] = count - 8;
    count = 0;
}

static void move_v(col_t *col, int current_map, sfVector2i box[2])
{
    int count = 0;

    for (int i = box[0].y; i > 0; i--) {
        if (i == 1 || col->maps[current_map]->map[i][box[0].x] == '1' ||
col->maps[current_map]->map[i][box[1].x] == '1') {
            count += ABS((int)(col->pos->y + col->hitbox.top) % CELL_SIZE);
            break;
        }
        count += CELL_SIZE;
    }
    col->max[UP] = count - 16;
    printf("UP : %f\n", col->max[UP]);
    count = 0;
    for (int i = box[1].y; i < col->maps[current_map]->size.y; i++) {
        if (i == 1 || col->maps[current_map]->map[i][box[0].x + 1] == '1' ||
col->maps[current_map]->map[i][box[1].x] == '1') {
            count -= ABS((int)(col->pos->y) % CELL_SIZE);
            break;
        }
        count += CELL_SIZE;
    }
    col->max[DOWN] = count - 4;
    count = 0;
}

void compute_col(col_t *col, int current_map)
{
    sfVector2i box[2];

    col->save.x = col->pos->x;
    col->save.y = col->pos->y;
    box[0].x = get_pos(col->pos->x + 1 + col->hitbox.left);
    box[0].y = get_pos(col->pos->y + 1 + col->hitbox.top);
    box[1].x = get_pos(col->pos->x - 1 + col->hitbox.left + col->hitbox.width);
    box[1].y = get_pos(col->pos->y - 1 + col->hitbox.top + col->hitbox.height);
    move_h(col, current_map, box);
    move_v(col, current_map, box);
}
