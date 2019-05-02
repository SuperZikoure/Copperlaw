/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** display_mobs.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "graph.h"
#include "my_rpg.h"
#include "macros.h"

static int compare_floats(float i, float j)
{
    float compare = i - j;

    compare = ABS(compare);
    if (compare <= 1) {
        return (1);
    }
    return (0);
}

static void display_npc(game_t *game, float pos)
{
    for (int i = 0; i < NPC_AMOUNT; i++) {
        if (!compare_floats(game->npc[i]->pos.y, pos))
            continue;
        if (game->npc[i]->map == game->current_map) {
            display_anim(game->npc[i]->display, game->npc[i]->pos);
        }
    }
}

static void display_player(player_t *player, float pos)
{
    if (!compare_floats(player->pos.y, pos))
        return;
    if (player->moving)
        display_anim(player->move, player->pos);
    else
        display_anim(player->idle, player->pos);
}

void display_mobs(game_t *game)
{
    sfVector2f size = global_to_view(V2F(0, 0), game->view);

    for (int i = size.y; i < VIEW_SIZE_Y + size.y; i++) {
        display_player(PLAYER, i);
        display_npc(game, i);
    }
}