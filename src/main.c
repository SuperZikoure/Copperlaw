/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main function
*/

#include "dialogues.h"
#include "my_string.h"
#include "my_stdio.h"
#include "utils.h"
#include "macros.h"

static bool has_display_env_variable(char const *env[])
{
    for (size_t i = 0; env[i]; i++) {
        if (my_strncmp("DISPLAY", env[i], 7))
            continue;
        return true;
    }
    return false;
}

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

static int game_main(void)
{
    game_t game = create_game();

    if (!is_game_valid(&game))
        return 84;
    if (fill_image(game.window) == -1 || fill_anim(game.window) == -1)
        return 84;
    if (!get_door_sound())
        return 84;
    my_srand();
    change_scene(MAIN_MENU);
    if (setup_dialogues() == -1)
        return 84;
    game_loop(&game);
    if (game.exit == -1)
        return 84;
    destroy_game(&game);
    return 0;
}

int main(int argc, char const *argv[], char const *env[])
{
    if (argc > 1) {
        my_dprintf(2, "Sorry, %s does not take any arguments\n", argv[0]);
        return 0;
    }
    if (!has_display_env_variable(env)) {
        my_dputs("ERROR: The current DISPLAY environement varible is not \
supported\n", 2);
        return 84;
    }
    return game_main();
}
