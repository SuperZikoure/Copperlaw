/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** change_animation
*/

#include "my_rpg.h"
#include "macros.h"

void change_anim(player_t *player)
{
    int speeds[4] = {ABS(player->speed.y), player->speed.x, player->speed.y,
ABS(player->speed.x)};
    int max = 0;
    sfVector2i dir;
    int current = 0;

    dir.x = (player->speed.x > 0) ? 1 : 3;
    dir.y = (player->speed.y > 0) ? 2 : 0;
    for (int i = 1; i < 4; i++)
        if (speeds[i] >= speeds[max])
            max = i;
    if (max % 2 != 0)
        current = dir.x;
    else
        current = dir.y;
    player->move->frame.left = current * player->move->frame.width;
    sfSprite_setTextureRect(player->move->sheet->sprite, player->move->frame);
}
