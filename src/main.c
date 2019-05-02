/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main function
*/

#include "graph.h"
#include "utils.h"
#include "my_rpg.h"

static sfBool is_game_valid(game_t *game)
{
    if (game->exit == -1)
        return sfFalse;
    if (!game->window || !game->input || !game->clock)
        return sfFalse;
    if (!game->view || !game->gui || !game->maps[0] || !game->player)
        return sfFalse;
    return sfTrue;
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
    game_loop(&game);
    if (game.exit == -1)
        return (84);
    return (0);
}
