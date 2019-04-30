/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** change_animation
*/

#include "my_rpg.h"
#include "macros.h"

static void set_speeds(player_t *player, int speeds[4])
{
    speeds[0] = ABS(player->speed.y);
    speeds[1] = player->speed.x;
    speeds[2] = player->speed.y;
    speeds[3] = ABS(player->speed.x);
}

void change_anim(player_t *player)
{
    int speeds[4];
    int dirs[2];
    int max = 0;
    int current = 0;

    set_speeds(player, speeds);
    dirs[0] = (player->speed.x > 0) ? 1 : 3;
    dirs[1] = (player->speed.y > 0) ? 2 : 0;
    for (int i = 1; i < 4; i++)
        if (speeds[i] >= speeds[max])
            max = i;
    if (max % 2 != 0)
        current = dirs[0];
    else
        current = dirs[1];
    player->move->frame.left = current * player->move->frame.width;
    sfSprite_setTextureRect(player->move->sheet->sprite, player->move->frame);
}
