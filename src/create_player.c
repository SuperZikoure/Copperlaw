/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** create_player.c
*/

#include <stdlib.h>
#include <math.h>
#include "graph.h"
#include "my_rpg.h"
#include "macros.h"

const float stat_init[STATS_AMOUNT] = {
    5,
    5,
    5,
    5,
    1,
    1,
    2.5,
    60,
    25,
    30,
    1500,
    1,
    1,
    0,
    5,
    1,
    0,
    0,
    0,
    0,
    0
};

static col_t create_col(sfVector3f hb, sfVector2f *pos, map_t *maps[MAP_AMOUNT])
{
    col_t col;

    for (int i = 0; i < 4; i++)
        col.max[i] = 100;
    for (int i = 0; i < MAP_AMOUNT; i++)
        col.maps[i] = maps[i];
    col.pos = pos;
    col.hitbox = hb;
    col.current_map = 0;
    col.save = V2F(0, 0);
    return (col);
}

static int init_player(game_t *ga, player_t *player)
{
    player->pos = V2F(160, 80);
    player->speed = V2F(0, 0);
    player->dash = V2F(0, 0);
    player->bump = V2F(0, 0);
    player->vel = V2F(0, 0);
    player->direction = UP;
    player->direction_2 = NORTH;
    player->dir = V2F(0, 0);
    player->mouse_distance = 0;
    player->idle = create_anim(V2F(8, 0), V2I(32, 32),
"assets/player/idle.png", ga->window);
    player->move = create_anim(V2F(12, 18), V2I(32, 32),
"assets/player/move.png", ga->window);
    if (!player->idle || !player->move)
        return -1;
    player->display = player->move;
    return 0;
}

static int init_attacks(player_t *player)
{
    for (int i = 0; i < PLAYER_BALLS; i++) {
        player->balls[i] = malloc(sizeof(ball_t));
        if (!player->balls[i])
            return -1;
        player->balls[i]->exist = 0;
    }
    return (0);
}

player_t *create_player(game_t *ga)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return NULL;
    if (init_player(ga, player) == -1 || init_attacks(player) == -1)
        return NULL;
    for (int i = 0; i < STATS_AMOUNT; i++) {
        player->boost[i] = 0;
        player->stats[i] = stat_init[i];
    }
    player->col = create_col(V3F(16, 24, 8), &player->pos, ga->maps);
    player->moving = 0;
    return (player);
}
