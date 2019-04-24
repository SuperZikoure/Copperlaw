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

const float stat_init[STATS_AMOUNT] = {
    30,
    30,
    15,
    15,
    3,
    3,
    2.5,
    60,
    25,
    30,
    1500,
    2,
    1,
    0,
    100,
    1,
    100,
    0,
    0,
    120,
    120
};

static col_t create_col(sfIntRect hb, sfVector2f pos, map_t *maps[MAP_AMOUNT])
{
    col_t col;

    for (int i = 0; i < 4; i++)
        col.max[i] = 100;
    for (int i = 0; i < MAP_AMOUNT; i++)
        col.maps[i] = maps[i];
    col.pos = &pos;
    col.hitbox = hb;
    col.current_map = 0;
    return (col);
}

player_t *create_player(game_t *ga)
{
    player_t *player = malloc(sizeof(player_t));

    player->pos = V2F(50, 50);
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
    player->display = player->move;
    for (int i = 0; i < PLAYER_BALLS; i++) {
        player->attacks[i] = malloc(sizeof(ball_t));
        player->attacks[i]->ball = create_image("assets/ball.png", ga->window);
        player->attacks[i]->pos = (sfVector2f){0, 0};
        player->attacks[i]->speed = (sfVector2f){0, 0};
        player->attacks[i]->exist = 0;
    }
    for (int i = 0; i < STATS_AMOUNT; i++) {
        player->boost[i] = 0;
        player->stats[i] = stat_init[i];
    }
    player->col = create_col((sfIntRect){0, 16, 16, 16},
    player->pos, ga->maps);
    return (player);
}