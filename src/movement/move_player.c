/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** move_player.c
*/

#include <stdlib.h>
#include <math.h>
#include "graph.h"
#include "my_rpg.h"
#include "macros.h"

#define MOVES_UP(dir) (dir & DIR_UP)
#define MOVES_DOWN(dir) (dir & DIR_DOWN)
#define MOVES_RIGHT(dir) (dir & DIR_RIGHT)
#define MOVES_LEFT(dir) (dir & DIR_LEFT)

#include <stdio.h>

void move_player(player_t *player, char dir)
{
    if (MOVES_UP(dir)) {
        player->speed.y = -player->stats[MOVE_SPEED];
    } else if (MOVES_DOWN(dir)) {
        player->speed.y = player->stats[MOVE_SPEED];
    }
    if (MOVES_RIGHT(dir)) {
        player->speed.x = player->stats[MOVE_SPEED];
    } else if (MOVES_LEFT(dir)) {
        player->speed.x = -player->stats[MOVE_SPEED];
    }
    change_anim(player);
}
