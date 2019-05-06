/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** game_option
*/

#include "my_rpg.h"
#include "macros.h"

int swap_main_menu_to_option(game_t *game __attribute__((unused)),
                        int option __attribute__((unused)))
{
    change_scene(OPTIONS);
    return 1;
}

int swap_option_to_main_menu(game_t *game __attribute__((unused)),
                        int option __attribute__((unused)))
{
    change_scene(MAIN_MENU);
    return 1;
}

int swap_menu_to_main_menu(game_t *game __attribute__((unused)),
                        int option __attribute__((unused)))
{
    change_scene(MAIN_MENU);
    destroy_music(game->music);
    game->music = load_music(GET_MUSIC_PATHS(MAIN_MENU_MUSIC));
    if (game->option.sound)
        start_music(game->music);
    return 1;
}
