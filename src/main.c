/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main function
*/

#include "dialogues.h"
#include "utils.h"

static sfBool is_game_valid(game_t *game)
{
    if (game->exit == -1)
        return sfFalse;
    if (!game->window || !game->input || !game->view)
        return sfFalse;
    if (!game->gui || !game->maps[0] || !game->player)
        return sfFalse;
    return sfTrue;
}

static int setup_dialogues(void)
{
    if (load_dialogue_scene(INTRO) == -1)
        return -1;
    if (!fetch_dialogue_canvas())
        return -1;
    return 0;
}

int main(void)
{
    game_t game = create_game();

    if (!is_game_valid(&game))
        return 84;
    if (fill_image(game.window) == -1)
        return (84);
    if (fill_anim(game.window) == -1)
        return (84);
    my_srand();
    change_scene(MAIN_MENU);
    if (setup_dialogues() == -1)
        return 84;
    game_loop(&game);
    if (game.exit == -1)
        return (84);
    return (0);
}
