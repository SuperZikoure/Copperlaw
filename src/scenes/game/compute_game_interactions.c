/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** movement_management
*/

#include "my_rpg.h"
#include "macros.h"
#include <stdio.h>

static sfVector2f cursor_dir(game_t *game)
{
    float vx = game->gui->cursor->pos.x - game->player->pos.x;
    float vy = game->gui->cursor->pos.y - game->player->pos.y;
    float total;

    total = ABS(vx) + ABS(vy);
    return (V2F(vx / total, vy / total));
}

static void update_bar(anim_t *bar, float value, float max)
{
    float frame = (int)(value / max * bar->frames);

    frame = bar->frames - frame;
    bar->frame.top = bar->size.y * frame;
    sfSprite_setTextureRect(bar->sheet->sprite, bar->frame);
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
    player_t *player = PLAYER;

    check_input_fire(game, dir);
    dash(game->input, &PLAYER->dash, PLAYER->speed, dir);
    analyse_movement_keys(game->input, game->player);
    update_bar(get_anim(LIFE_BAR), STATS(CURRENT_HP), STATS(MAX_HP));
    update_bar(get_anim(MANA_BAR), STATS(CURRENT_MP), STATS(MAX_MP));
    STATS(CURRENT_MP) += 0.02;
    if (STATS(CURRENT_MP) > STATS(MAX_MP))
        STATS(CURRENT_MP) = STATS(MAX_MP);
    STATS(CURRENT_SP) += 0.001;
    if (STATS(CURRENT_SP) > STATS(MAX_SP))
        STATS(CURRENT_SP) = STATS(MAX_SP);
}
