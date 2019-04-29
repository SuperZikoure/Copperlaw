/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display_cursor
*/

#include "my_rpg.h"
#include "macros.h"

static float get_distance(sfVector2f p1, sfVector2f p2)
{
    float distance = ABS(sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)));

    return (distance);
}

void display_cursor(game_t *game, sfVector2f view_pos[4])
{
    float distance;

    distance = get_distance(PLAYER->pos, view_pos[3]);
    if (distance >= 15 && distance < 40)
        display_image(get_image(TRAIL_1), view_pos[0]);
    else if (distance >= 40) {
        display_image(get_image(TRAIL_2), view_pos[0]);
        display_image(get_image(TRAIL_1), view_pos[1]);
        display_image(get_image(TRAIL_1), view_pos[2]);
    }
}
