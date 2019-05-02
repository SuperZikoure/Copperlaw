/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** compute_dialogue_interactions
*/

#include "dialogues.h"
#include "macros.h"

static int analyse_choise_mouse(game_t *game, struct selection *s)
{
    int found = 0;
    int selected = -1;
    int save = s->selected;

    for (int i = 0; i < s->total; i++) {
        if (text_intersect(s->texts[i], CURSOR->display->sheet)) {
            selected = i;
            found = 1;
        }
    }
    for (int i = 0; i < s->total && found; i++) {
        s->selected = i;
        if (i == selected)
            change_selected_choise_color(s, sfYellow);
        else
            change_selected_choise_color(s, sfWhite);
    }
    s->selected = (selected != -1) ? selected : save;
    if (MOUSE_PRESSED(sfMouseLeft) && found)
        return (s->selected);
    return (-1);
}

static int analyse_choise_inputs(input_t *input, struct selection *s)
{
    if (KEY_PRESSED(ENTER_KEY) || KEY_PRESSED(SPACE_KEY))
        return s->selected;
    if (KEY_PRESSED(LEFT_KEY) && s->selected > 0) {
        change_selected_choise_color(s, sfWhite);
        s->selected--;
        change_selected_choise_color(s, sfYellow);
    }
    if (KEY_PRESSED(RIGHT_KEY) && s->selected < s->total - 1) {
        change_selected_choise_color(s, sfWhite);
        s->selected++;
        change_selected_choise_color(s, sfYellow);
    }
    return -1;
}

int compute_dialogues_interactions(game_t *game)
{
    input_t *input = game->input;
    int n_choise = -1;

    if (game->dialogue->choises && game->dialogue->n_frames == -1) {
        n_choise = analyse_choise_inputs(input, game->dialogue->choises);
        if (n_choise == -1)
            n_choise = analyse_choise_mouse(game, game->dialogue->choises);
        if (n_choise != -1)
            game->dialogue = switch_dialogue(game->dialogue);
        return n_choise;
    }
    if (KEY_PRESSED(SPACE_KEY) || MOUSE_PRESSED(sfMouseLeft)) {
        if (game->dialogue->n_frames == -1)
            game->dialogue = switch_dialogue(game->dialogue);
        else
            game->dialogue->speed = INSTANT;
    }
    return -1;
}
