/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** destroy_game
*/

#include <stdlib.h>
#include "my.h"
#include "dialogues.h"

static void destroy_gui(gui_t *gui)
{
    destroy_anim(gui->cursor->base);
    destroy_anim(gui->cursor->idle);
    destroy_anim(gui->cursor->build);
    destroy_anim(gui->cursor->inspect);
    free(gui->cursor);
    for (int i = 0; i < BUTTON_AMOUNT; i++) {
        destroy_image(gui->button[i]->base);
        destroy_image(gui->button[i]->hover);
        destroy_image(gui->button[i]->click);
        destroy_sound(gui->button[i]->hover_sound);
        destroy_sound(gui->button[i]->click_sound);
        free(gui->button[i]);
    }
    free(gui);
}

static void destroy_maps(map_t **maps)
{
    for (size_t i = 0; i < MAP_AMOUNT; i++) {
        my_free_fields(maps[i]->map);
        destroy_image(maps[i]->bg);
        destroy_image(maps[i]->fg);
    }
}

static void destroy_player(player_t *player)
{
    destroy_anim(player->idle);
    destroy_anim(player->move);
    for (size_t i = 0; i < PLAYER_BALLS; i++) {
        destroy_image(player->attacks[i]->ball);
        free(player->attacks[i]);
    }
    free(player);
}

int destroy_game(game_t *game)
{
    destroy_window(game->window);
    destroy_input(game->input);
    sfView_destroy(game->view->camera);
    free(game->view);
    destroy_gui(game->gui);
    destroy_maps(game->maps);
    destroy_player(game->player);
    for (size_t i = 0; i < NPC_AMOUNT; i++) {
        destroy_anim(game->npc[i]->display);
        free(game->npc[i]);
    }
    destroy_current_dialogue_script();
    for (size_t i = 0; i < IMAGE_AMOUNT; i++)
        destroy_image(get_image(i));
    for (size_t i = 0; i < ANIM_AMOUNT; i++)
        destroy_anim(get_anim(i));
    destroy_dialogue_canvas();
    destroy_door_sound();
    destroy_music(game->music);
    return 0;
}
