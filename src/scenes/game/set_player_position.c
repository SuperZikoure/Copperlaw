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
    compute_col(&PLAYER->col, 0);
    printf("R: %.2f L: %.2f U: %.2f D: %.2f\n", PLAYER->col.max[RIGHT], PLAYER->col.max[LEFT], PLAYER->col.max[UP], PLAYER->col.max[DOWN]);
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
    game->player->vel.x = game->player->speed.x + game->player->dash.x;
    game->player->vel.y = game->player->speed.y + game->player->dash.y;
    game->player->vel.x *= get_delta();
    game->player->vel.y *= get_delta();
    collision_update(game);
    if (ABS(game->player->dash.x) + ABS(game->player->dash.y))
        game->player->moving = 0;
    if ((!PLAYER->vel.x && !PLAYER->vel.y) || game->player->dash.x ||
game->player->dash.y) {
        PLAYER->moving = 0;
        set_idle_animation(game);
    } else
        PLAYER->moving = 1;
    PLAYER->pos.x += PLAYER->vel.x;
    PLAYER->pos.y += PLAYER->vel.y;
    update_anim(game->player->display);
}
