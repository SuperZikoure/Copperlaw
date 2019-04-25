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

static void change_anim(player_t *player)
{
    int speeds[4] = {ABS(player->speed.y), player->speed.x, player->speed.y,
ABS(player->speed.x)};
    int max = 0;
    sfVector2i dir;
    int current = 0;

    dir.x = (player->speed.x > 0) ? 1 : 3;
    dir.y = (player->speed.y > 0) ? 2 : 0;
    for (int i = 0; i < 4; i++)
        if (speeds[i] >= speeds[max])
            max = i;
    if (max % 2 != 0)
        current = dir.x;
    else
        current = dir.y;
    player->move->frame.left = current * player->move->frame.width;
    sfSprite_setTextureRect(player->move->sheet->sprite, player->move->frame);
}

void move_player(player_t *player, int dir)
{
    if (dir == UP) {
        player->speed.y = -player->stats[MOVE_SPEED];
    }
    if (dir == RIGHT) {
        player->speed.x = player->stats[MOVE_SPEED];
    }
    if (dir == DOWN) {
        player->speed.y = player->stats[MOVE_SPEED];
    }
    if (dir == LEFT) {
        player->speed.x = -player->stats[MOVE_SPEED];
    }
    change_anim(player);
}
