/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** analyse_movement_keys
*/

#include "my_rpg.h"
#include "macros.h"

static char get_direction(input_t *input)
{
    char dir = 0;

    if (KEY_HELD(UP_KEY) ^ KEY_HELD(DOWN_KEY)) {
        if (KEY_HELD(UP_KEY))
            dir |= DIR_UP;
        if (KEY_HELD(DOWN_KEY))
            dir |= DIR_DOWN;
    }
    if (KEY_HELD(LEFT_KEY) ^ KEY_HELD(RIGHT_KEY)) {
        if (KEY_HELD(LEFT_KEY))
            dir |= DIR_LEFT;
        if (KEY_HELD(RIGHT_KEY))
            dir |= DIR_RIGHT;
    }
    return dir;
}

void analyse_movement_keys(input_t *input, player_t *player)
{
    char dir = get_direction(input);

    move_player(player, dir);
    player->speed.x += (player->speed.x > 0) ? -0.45 : 0.45;
    player->speed.y += (player->speed.y > 0) ? -0.45 : 0.45;
    if (player->speed.x <= 0.46 && player->speed.x >= -0.46)
        player->speed.x = 0;
    if (player->speed.y <= 0.46 && player->speed.y >= -0.46)
        player->speed.y = 0;
}
