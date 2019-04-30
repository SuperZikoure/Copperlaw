/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** loop_game
*/

#include <stdio.h>
#include "my_rpg.h"

static void analyse_input(input_t *input)
{
    int scene_id = get_scene_id();

    printf("P: %d H: %d\n", KEY_PRESSED(ESCAPE_KEY), KEY_HELD(ESCAPE_KEY));
    if (KEY_PRESSED(ESCAPE_KEY)) {
        if (scene_id == GAME)
            change_scene(PAUSE);
        else if (scene_id == PAUSE)
            change_scene(GAME);
        // input->keys[ESCAPE_KEY]->pressed = 0;
    }
}

void game_loop(game_t *game)
{
    change_scene(GAME);
    start_clock();
    while (sfRenderWindow_isOpen(game->window->window) && !game->exit) {
        start_new_frame();
        process_input(game->window, game->input);
        game->mouse_pos = sfMouse_getPositionRenderWindow(game->window->window);
        analyse_input(game->input);
        sfRenderWindow_clear(game->window->window, sfBlack);
        /* if ( */get_scene()(game);/*  == -1) */
            // sfRenderWindow_close(game->window->window);
        sfRenderWindow_setView(game->window->window, game->view->camera);
        sfRenderWindow_display(game->window->window);
    }
}
