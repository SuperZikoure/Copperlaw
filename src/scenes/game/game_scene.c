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
#include "macros.h"

// void reset_velocity(sfVector2f *velocity, float rate)
// {
//     if (velocity->x != 0)
//         velocity->x -= (velocity->x > 0) ? rate : -rate;
//     if (velocity->y != 0)
//         velocity->y -= (velocity->y > 0) ? rate : -rate;
//     if (velocity->x >= rate && velocity->x <= - rate)
//         velocity->x = 0;
//     if (velocity->y >= rate && velocity->y <= - rate)
//         velocity->y = 0;
// }

// void manage_michel(monster_t *michel, ball_t *balls[PLAYER_BALLS], sfVector2f pos)
// {
//         sfVector2f diff = (sfVector2f){michel->pos.x - pos.x, michel->pos.y - pos.y};

//     for (int i = 0; i < PLAYER_BALLS; i++) {
//         if (!balls[i]->exist)
//             continue;
//         if ((michel->speed.x + michel->speed.y && image_intersect(balls[i]->ball, michel->hit)) || (!(michel->speed.x + michel->speed.y) && image_intersect(balls[i]->ball, michel->normal))) {
//             michel->speed = (sfVector2f){balls[i]->speed.x / 5, balls[i]->speed.y / 5};
//             balls[i]->exist = 0;
//         }
//     }
//     if (ABS(diff.x) <= 200 && ABS(diff.y) <= 200)
//         michel->aggro = 1;
//     else
//         michel->aggro = 0;
//     if (michel->aggro) {
//         michel->speed.x += (diff.x <= 0) ? 0.6 : -0.6;
//         michel->speed.y += (diff.y <= 0) ? 0.6 : -0.6;
//     }
//     michel->pos.x += michel->speed.x;
//     michel->pos.y += michel->speed.y;
//     reset_velocity(&michel->speed, 1);
//     if (michel->speed.x <= 1.01 && michel->speed.x >= -1.01)
//         michel->speed.x = 0;
//     if (michel->speed.y <= 1.01 && michel->speed.y >= -1.01)
//         michel->speed.y = 0;
//     if (michel->speed.x + michel->speed.y)
//         display_image(michel->hit, michel->pos);
//     else
//         display_image(michel->normal, michel->pos);
// }

static void player_management(game_t *game)
{
    compute_game_interactions(game);
    set_player_position(game);
    if (game->player->moving)
        display_anim(game->player->move, game->player->pos);
    else
        display_anim(game->player->idle, game->player->pos);
}

static int analyse_game_events(game_t *game, input_t *input)
{
    if (KEY_PRESSED(ESCAPE_KEY))
        return swap_game_to_menu(game);
    return 0;
}

int game_scene(game_t *game)
{
    if (analyse_game_events(game, game->input))
        return 1;
    display_image(game->maps[game->current_map]->bg, V2F(0, 0));
    player_management(game);
    update_game_gui(game);
    return 0;
}
