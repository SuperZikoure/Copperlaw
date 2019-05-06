/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** mainmenu_game
*/

#include "my_rpg.h"
#include "macros.h"

int swap_main_menu_to_game(game_t *game, int option __attribute__((unused)))
{
    change_scene(GAME);
    CURSOR->mode = CURSOR_IDLE;
    destroy_music(game->music);
    game->music = load_music(GET_MUSIC_PATHS(WILD_MUSIC));
    if (game->option.sound) {
        sfMusic_setVolume(game->music->cover, BASE_VOLUME);
        start_music(game->music);
    }
    return 1;
}
