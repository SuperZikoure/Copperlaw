/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** fire_balls.c
*/

#include "my_rpg.h"

/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** fire_ball
*/

#include "my_rpg.h"

void display_balls(ball_t *balls[PLAYER_BALLS])
{
    for (int i = 0; i < PLAYER_BALLS; i++) {
        if (!balls[i]->exist)
            continue;
        balls[i]->pos.x += balls[i]->speed.x;
        balls[i]->pos.y += balls[i]->speed.y;
        if (!balls[i]->skill)
            display_image(get_image(WHITE_BALL), balls[i]->pos);
    }
}

void fire_ball(game_t *game, sfVector2f dir, int type, int skill)
{
    int x = PLAYER->pos.x + 16;
    int y = PLAYER->pos.y + 16;

    for (int i = 0; i < PLAYER_BALLS; i++) {
        if (PLAYER->balls[i]->exist)
            continue;
        PLAYER->balls[i]->exist = 1;
        PLAYER->balls[i]->pos.x = x;
        PLAYER->balls[i]->pos.y = y;
        PLAYER->balls[i]->speed.x = dir.x * game->player->stats[ATTACK_SPEED];
        PLAYER->balls[i]->speed.y = dir.y * game->player->stats[ATTACK_SPEED];
        PLAYER->balls[i]->damage = PLAYER->stats[DAMAGE];
        PLAYER->balls[i]->type = type;
        PLAYER->balls[i]->skill = skill;
        return;
    }
}
