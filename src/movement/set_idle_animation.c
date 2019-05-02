/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** set_idle_animation
*/

#include "my_rpg.h"
#include "macros.h"

static int get_player_direction(game_t *game)
{
    int direction;
    float angle;
    double y = PLAYER->pos.x - CURSOR->pos.x;
    double x = PLAYER->pos.y - CURSOR->pos.y;

    if (!game->player->moving)
        angle = 8 - DEG(atan2(y, x)) / 45;
    direction = round(angle);
    direction %= 8;
    return (direction);
}

void set_idle_animation(game_t *game)
{
    int dir = get_player_direction(game);

    if (!game->dialogue) {
        PLAYER->idle->frame.top = dir * PLAYER->idle->frame.height;
        sfSprite_setTextureRect(PLAYER->idle->sheet->sprite, PLAYER->idle->frame);
    }
}
