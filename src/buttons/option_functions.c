/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** menu_functions.c
*/

#include "my_rpg.h"
#include "macros.h"

int change_fullscreen_mode(game_t *game, int option __attribute__((unused)))
{
    FS = FS ? false : true;
    change_window(game->window, RES, FS);
    return 1;
}

int icr_resolution(game_t *game, int option __attribute__((unused)))
{
    if (RES < RESOLUTIONS - 1) {
        ++RES;
        change_window(game->window, RES, FS);
    }
    return 1;
}

int dcr_resolution(game_t *game, int option __attribute__((unused)))
{
    if (RES > 0) {
        --RES;
        change_window(game->window, RES, FS);
    }
    return 1;
}

int change_sound(game_t *game, int option __attribute__((unused)))
{
    button_t *button = find_button(game, "sound", OPTIONS);
    sfColor color = {255, 255, 255, game->sound ? 100 : 255};
    float volume = game->sound ? 0 : BASE_VOLUME;

    game->sound = game->sound ? false : true;
    sfSprite_setColor(button->base->sprite, color);
    sfSprite_setColor(button->hover->sprite, color);
    sfSprite_setColor(button->click->sprite, color);
    for (int i = 0; i < BUTTON_AMOUNT; i++) {
        sfSound_setVolume(GUI->button[i]->click_sound->sound, volume);
        sfSound_setVolume(GUI->button[i]->hover_sound->sound, volume);
    }
    return 1;
}
