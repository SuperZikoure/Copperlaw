/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** manage_collisions.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_rpg.h"
#include "macros.h"

static int get_pos(int pos)
{
    int value = 0;

    value = pos - (pos % C_SIZE);
    value /= C_SIZE;
    return (value);
}

static void move_h(col_t *col, int current_map)
{
    int count = 0;
    int x = get_pos(col->pos->x + col->hitbox.x);
    int y = get_pos(col->pos->y + col->hitbox.y);

    for (int i = x - 1; i >= 0; i--) {
        if (col->maps[current_map]->map[y][i] == '1') {
            count += (int) (col->pos->x + col->hitbox.x) % C_SIZE;
            break;
        }
        count += C_SIZE;
    }
    col->max[LEFT] = count - col->hitbox.z;
    count = 0;
    for (int i = x + 1; i < col->maps[current_map]->size.x; i++) {
        if (col->maps[current_map]->map[y][i] == '1') {
            count += C_SIZE - ((int) (col->pos->x + col->hitbox.x) % C_SIZE);
            break;
        }
        count += C_SIZE;
    }
    col->max[RIGHT] = count - col->hitbox.z;
}

static void move_v(col_t *col, int current_map)
{
    int count = 0;
    int x = get_pos(col->pos->x + col->hitbox.x);
    int y = get_pos(col->pos->y + col->hitbox.y);

    for (int i = y - 1; i >= 0; i--) {
        if (col->maps[current_map]->map[i][x] == '1') {
            count += (int) (col->pos->y + col->hitbox.y) % C_SIZE;
            break;
        }
        count += C_SIZE;
    }
    col->max[UP] = count - col->hitbox.z;
    count = 0;
    for (int i = y + 1; i < col->maps[current_map]->size.y; i++) {
        if (col->maps[current_map]->map[i][x] == '1') {
            count += C_SIZE - ((int) (col->pos->y + col->hitbox.y) % C_SIZE);
            break;
        }
        count += C_SIZE;
    }
    col->max[DOWN] = count - col->hitbox.z;
}

void compute_col(col_t *col, int current_map)
{
    col->save.x = col->pos->x;
    col->save.y = col->pos->y;

    move_h(col, current_map);
    move_v(col, current_map);
}
