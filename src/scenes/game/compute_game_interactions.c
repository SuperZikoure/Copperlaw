/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** movement_management
*/

#include "my_rpg.h"
#include "macros.h"

static sfVector2f cursor_dir(game_t *game)
{
    float vx = ABS(game->gui->cursor->pos.x - game->player->pos.x);
    float vy = ABS(game->gui->cursor->pos.y - game->player->pos.y);
    float total = vx + vy;

    return (V2F(vx / total, vy / total));
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

void compute_game_interactions(game_t *game)
{
    sfVector2f dir = cursor_dir(game);

    // if (mouse_pressed_once(sfMouseLeft))
    //    fire_ball(game->player->pos, game->game.balls, dir);
    dash(game->input, &PLAYER->dash, PLAYER->speed, dir);
    analyse_movement_keys(game->input, game->player);
}
