/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** loop_game
*/

#include "dialogues.h"

static int display_window(window_t *window, input_t *input)
{
    if (KEY_PRESSED(SCREENSHOT_KEY))
        do_screenshot(window);
    sfRenderWindow_display(window->window);
    return 0;
}

static int setup_dialogues(void)
{
    if (load_dialogue_scene(INTRO) == -1)
        return -1;
    if (!fetch_dialogue_canvas())
        return -1;
    return 0;
}

void game_loop(game_t *game)
{
    change_scene(MAIN_MENU);
    if (setup_dialogues() == -1)
        game->exit = -1;
    start_clock();
    while (sfRenderWindow_isOpen(game->window->window) && !game->exit) {
        start_new_frame();
        if (analyse_events(game))
            break;
        game->mouse_pos = sfMouse_getPositionRenderWindow(game->window->window);
        update_fetch_anim();
        sfRenderWindow_clear(game->window->window, sfBlack);
        if (get_scene()(game) == -1)
            game->exit = -1;
        sfRenderWindow_setView(game->window->window, game->view->camera);
        display_window(WINDOW, game->input);
    }
    if (!sfRenderWindow_isOpen(game->window->window))
        sfRenderWindow_close(game->window->window);
}