/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main function
*/

#include "graph.h"
#include "my_rpg.h"

int main(void)
{
    game_t game = create_game();

    if (fill_image(game.window) == -1)
        return (84);
    game.scene = GAME;
    game_loop(&game);
    if (game.exit == -1)
        return (84);
    return (0);
}
