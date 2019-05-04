/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** manage_movement
*/

#include "my_rpg.h"
#include "macros.h"

#include <stdio.h>

static void collision_update(game_t *game)
{
    compute_col(&PLAYER->col, game->current_map);
    if (PLAYER->vel.x > PLAYER->col.max[RIGHT])
        PLAYER->vel.x = PLAYER->col.max[RIGHT];
    if (-PLAYER->vel.x > PLAYER->col.max[LEFT])
        PLAYER->vel.x = -PLAYER->col.max[LEFT];
    if (PLAYER->vel.y > PLAYER->col.max[DOWN])
        PLAYER->vel.y = PLAYER->col.max[DOWN];
    if (-PLAYER->vel.y > PLAYER->col.max[UP])
        PLAYER->vel.y = -PLAYER->col.max[UP];
}

void set_player_position(game_t *game)
{
    PLAYER->vel.x = PLAYER->speed.x + PLAYER->dash.x;
    PLAYER->vel.y = PLAYER->speed.y + PLAYER->dash.y;
    PLAYER->vel.x *= get_delta();
    PLAYER->vel.y *= get_delta();
    collision_update(game);
    if ((!PLAYER->vel.x && !PLAYER->vel.y) || PLAYER->dash.x ||
PLAYER->dash.y) {
        PLAYER->moving = 0;
        set_idle_animation(game);
    } else
        PLAYER->moving = 1;
    PLAYER->pos.x += PLAYER->vel.x;
    PLAYER->pos.y += PLAYER->vel.y;
    update_anim(PLAYER->display);
}
