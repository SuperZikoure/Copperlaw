/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** game_scene.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "graph.h"
#include "my_rpg.h"

void reset_velocity(sfVector2f *velocity, float rate)
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

sfBool mouse_pressed_once(int mouse_button)
{
    static sfBool press[3] = {0, 0, 0};
    static sfBool click[3] = {0, 0, 0};

    if (sfMouse_isButtonPressed(mouse_button) && !click[mouse_button]) {
        press[mouse_button] = 1;
        click[mouse_button] = 1;
    } else {
        press[mouse_button] = 0;
    }
    if (!sfMouse_isButtonPressed(mouse_button)){
        press[mouse_button] = 0;
        click[mouse_button] = 0;
    }
    return (press[mouse_button]);
}

void manage_view(sfVector2f pos, view_t *view)
{
    sfVector2f center;

    if (pos.x < view->pos.left)
        view->pos.left = pos.x;
    if (pos.x > view->pos.left + view->pos.width)
        view->pos.left = pos.x - view->pos.width;
    if (pos.y < view->pos.top)
        view->pos.top = pos.y;
    if (pos.y > view->pos.top + view->pos.height)
        view->pos.top = pos.y - view->pos.height;
    center.x = view->pos.left + view->pos.width/2;
    center.y = view->pos.top + view->pos.height/2;
    sfView_setCenter(view->camera, center);
}

void manage_inputs(input_t *input, player_t *player)
{
    if (KEY_HELD(UP_KEY) == 1)
        move_player(player, UP);
    if (KEY_HELD(DOWN_KEY) == 1)
        move_player(player, DOWN);
    if (KEY_HELD(UP_KEY) == 1 && KEY_HELD(DOWN_KEY) == 1)
        player->speed.y = 0;
    if (KEY_HELD(LEFT_KEY) == 1)
        move_player(player, LEFT);
    if (KEY_HELD(RIGHT_KEY) == 1)
        move_player(player, RIGHT);
    if (KEY_HELD(LEFT_KEY) == 1 && KEY_HELD(RIGHT_KEY) == 1)
        player->speed.x = 0;
    player->speed.x += (player->speed.x > 0) ? -0.45 : 0.45;
    player->speed.y += (player->speed.y > 0) ? -0.45 : 0.45;
    if (player->speed.x <= 0.46 && player->speed.x >= -0.46)
        player->speed.x = 0;
    if (player->speed.y <= 0.46 && player->speed.y >= -0.46)
        player->speed.y = 0;
}

void manage_dash(input_t *input, sfVector2f *dash, sfVector2f velocity, sfVector2f direction)
{
    static int timer = 0;
    int dir = ABS(velocity.x) + ABS(velocity.y);

    if (KEY_HELD(SPACE_KEY) == 1 && timer == 0 && dir >= 0.5) {
        timer = 60;
        if (ABS(velocity.x) - ABS(velocity.y) >= 1) {
            dash->x = velocity.x * 6.5;
            dash->y = velocity.y * 6.5;
        } else {
            dash->x = velocity.x * 5;
            dash->y = velocity.y * 5;
        }
    } else if (KEY_HELD(SPACE_KEY) == 1 && timer == 0) {
        timer = 60;
        if ((direction.x >= 0.2 && direction.x <= 0.8) ||
        (direction.x <= -0.2 && direction.x >= -0.8)) {
            dash->x = direction.x * 25;
            dash->y = direction.y * 25;
        } else {
            dash->x = direction.x * 15;
            dash->y = direction.y * 15;
        }
    }
    dash->x += (dash->x > 0) ? -1 : 1;
    dash->y += (dash->y > 0) ? -1 : 1;
    if (dash->x <= 1.01 && dash->x >= -1.01)
        dash->x = 0;
    if (dash->y <= 1.01 && dash->y >= -1.01)
        dash->y = 0;
    if (timer > 0)
        timer--;
}

sfVector2f ball_dir(game_t *game)
{
    float vx = game->gui->cursor->pos.x - game->player->pos.x;
    float vy = game->gui->cursor->pos.y - game->player->pos.y;
    float total = ABS(vx) + ABS(vy);

    return ((sfVector2f){vx / total, vy / total});
}

void manage_michel(monster_t *michel, ball_t *balls[PLAYER_BALLS], sfVector2f pos)
{
        sfVector2f diff = (sfVector2f){michel->pos.x - pos.x, michel->pos.y - pos.y};

    for (int i = 0; i < PLAYER_BALLS; i++) {
        if (!balls[i]->exist)
            continue;
        if ((michel->speed.x + michel->speed.y && image_intersect(balls[i]->ball, michel->hit)) || (!(michel->speed.x + michel->speed.y) && image_intersect(balls[i]->ball, michel->normal))) {
            michel->speed = (sfVector2f){balls[i]->speed.x / 5, balls[i]->speed.y / 5};
            balls[i]->exist = 0;
        }
    }
    if (ABS(diff.x) <= 200 && ABS(diff.y) <= 200)
        michel->aggro = 1;
    else
        michel->aggro = 0;
    if (michel->aggro) {
        michel->speed.x += (diff.x <= 0) ? 0.6 : -0.6;
        michel->speed.y += (diff.y <= 0) ? 0.6 : -0.6;
    }
    michel->pos.x += michel->speed.x;
    michel->pos.y += michel->speed.y;
    reset_velocity(&michel->speed, 1);
    if (michel->speed.x <= 1.01 && michel->speed.x >= -1.01)
        michel->speed.x = 0;
    if (michel->speed.y <= 1.01 && michel->speed.y >= -1.01)
        michel->speed.y = 0;
    if (michel->speed.x + michel->speed.y)
        display_image(michel->hit, michel->pos);
    else
        display_image(michel->normal, michel->pos);
}

void manage_balls(ball_t *balls[PLAYER_BALLS])
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

float get_distance(sfVector2f p1, sfVector2f p2)
{
    float distance = ABS(sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)));

    return (distance);
}

int get_player_direction(game_t *game)
{
    int direction;
    float angle;

    if (!game->player->moving) {
        angle = 8 - DEG(atan2(PLAYER->pos.x - CURSOR->pos.x,
PLAYER->pos.y - CURSOR->pos.y)) / 45;
    }
    direction = round(angle);
    direction %= 8;
    printf("DIRECTION : %d\n", direction);
    return (direction);
}

void manage_game(game_t *game)
{
    sfVector2f dir = ball_dir(game);
    sfVector2f view_pos[4];
    float distance;

    game->gui->cursor->pos.x -= 8;
    game->gui->cursor->pos.y -= 8;

    view_pos[0] = (sfVector2f){CAM(game->player->pos.x, game->gui->cursor->pos.x, 1) + 8, CAM(game->player->pos.y, game->gui->cursor->pos.y, 1) + 8};
    view_pos[1] = (sfVector2f){CAM(game->player->pos.x, game->gui->cursor->pos.x, 0.35) + 8, CAM(game->player->pos.y, game->gui->cursor->pos.y, 0.35) + 8};
    view_pos[2] = (sfVector2f){CAM(game->player->pos.x, game->gui->cursor->pos.x, 3) + 8, CAM(game->player->pos.y, game->gui->cursor->pos.y, 3) + 8};
    view_pos[3] = (sfVector2f){CAM(game->player->pos.x, game->gui->cursor->pos.x, 4), CAM(game->player->pos.y, game->gui->cursor->pos.y, 4)};

    distance = get_distance(game->player->pos, view_pos[3]);

    if (mouse_pressed_once(sfMouseLeft))
        fire_ball(game->player->pos, game->game.balls, dir);
    manage_dash(game->input, &game->player->dash, game->player->speed, dir);
    manage_inputs(game->input, game->player);

    //game->game.player_pos.x += game->game.player_speed.x + game->game.dash.x;
    //game->game.player_pos.y += game->game.player_speed.y + game->game.dash.y;

    game->player->pos.x += game->player->speed.x + game->player->dash.x;
    game->player->pos.y += game->player->speed.y + game->player->dash.y;

    game->player->moving = ABS(game->player->speed.x) +
    ABS(game->player->speed.y);
    if (ABS(game->player->dash.x) + ABS(game->player->dash.y))
        game->player->moving = 0;
    
    if (!game->player->moving) {
        PLAYER->idle->frame.top = get_player_direction(game) * PLAYER->idle->frame.height;
        sfSprite_setTextureRect(PLAYER->idle->sheet->sprite, PLAYER->idle->frame);
    }

    manage_view(view_pos[3], game->view);
    display_image(game->maps[game->current_map]->bg, (sfVector2f){0, 0});
    manage_balls(game->game.balls);
    manage_michel(game->game.michel, game->game.balls, game->game.player_pos);
    update_anim(game->player->display);
    if (game->player->moving)
        display_anim(game->player->move, game->player->pos);
    else
        display_anim(game->player->idle, game->player->pos);
    if (distance >= 15 && distance < 40)
        display_image(game->game.test1, view_pos[0]);
    else if (distance >= 40) {
        display_image(game->game.test2, view_pos[0]);
        display_image(game->game.test1, view_pos[1]);
        display_image(game->game.test1, view_pos[2]);
    }
}