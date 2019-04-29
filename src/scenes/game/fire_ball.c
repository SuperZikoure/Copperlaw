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
        display_image(balls[i]->ball, balls[i]->pos);
    }
}

void fire_ball(sfVector2f pos, ball_t *balls[PLAYER_BALLS], sfVector2f dir)
{
    int x = pos.x + 16;
    int y = pos.y + 16;
    static int ball = 0;

    for (int i = 0; i < PLAYER_BALLS; i++) {
        if (balls[i]->exist)
            continue;
        balls[i]->exist = 1;
        balls[i]->pos.x = x;
        balls[i]->pos.y = y;
        balls[i]->speed.x = dir.x * 20;
        balls[i]->speed.y = dir.y * 20;
        return;
    }
    balls[ball]->exist = 1;
    balls[ball]->pos.x = x;
    balls[ball]->pos.y = y;
    balls[ball]->speed.x = dir.x * 20;
    balls[ball]->speed.y = dir.y * 20;
    ball++;
    if (ball >= PLAYER_BALLS)
        ball = 0;
}
