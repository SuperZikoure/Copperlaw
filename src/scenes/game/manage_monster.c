/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** manage_monster.c
*/

#include "my_rpg.h"

static void reset_velocity(sfVector2f *velocity, float rate)
{
    if (velocity->x != 0)
        velocity->x -= (velocity->x > 0) ? rate : -rate;
    if (velocity->y != 0)
        velocity->y -= (velocity->y > 0) ? rate : -rate;
    if (velocity->x >= rate && velocity->x <= - rate)
        velocity->x = 0;
    if (velocity->y >= rate && velocity->y <= - rate)
        velocity->y = 0;
}

static void manage_monster_2(monster_t *monster, ball_t *balls[PLAYER_BALLS],
                        sfVector2f pos)
{
    if (ABS(diff.x) <= 200 && ABS(diff.y) <= 200)
        monster->aggro = 1;
    else
        monster->aggro = 0;
    if (monster->aggro) {
        monster->speed.x += (diff.x <= 0) ? 0.6 : -0.6;
        monster->speed.y += (diff.y <= 0) ? 0.6 : -0.6;
    }
    monster->pos.x += monster->speed.x;
    monster->pos.y += monster->speed.y;
    reset_velocity(&monster->speed, 1);
    if (monster->speed.x <= 1.01 && monster->speed.x >= -1.01)
        monster->speed.x = 0;
    if (monster->speed.y <= 1.01 && monster->speed.y >= -1.01)
        monster->speed.y = 0;
    if (monster->speed.x + monster->speed.y)
        display_image(monster->hit, monster->pos);
    else
        display_image(monster->normal, monster->pos);
}

monster_t *create_monster(sfVector2f pos, windows_t *window)
{
    monster_t *monster = my_realloc_array(sizeof(monster_t));

    monster->pos = pos;
    monster->speed = V2F(0, 0);
    monster->bump = V2F(0, 0);
    monster->aggro = 0;
    monster->hp = 10;
    monster->normal = create_image("assets/normal.png", window);
    monster->hit = create_image("assets/hit.png", window);
    return (monster);
}

void manage_monster(monster_t *monster, ball_t *balls[PLAYER_BALLS],
                    sfVector2f pos)
{
        sfVector2f diff = V2F(monster->pos.x - pos.x, monster->pos.y -pos.y);

    for (int i = 0; i < PLAYER_BALLS; i++) {
        if (!balls[i]->exist)
            continue;
        if ((monster->speed.x + monster->speed.y &&
        image_intersect(balls[i]->ball, monster->hit)) ||
        (!(monster->speed.x + monster->speed.y) &&
        image_intersect(balls[i]->ball, monster->normal))) {
            monster->speed = (sfVector2f){balls[i]->speed.x / 5,
            balls[i]->speed.y / 5};
            balls[i]->exist = 0;
        }
    }
    manage_monster_2(monster, balls, pos);
}