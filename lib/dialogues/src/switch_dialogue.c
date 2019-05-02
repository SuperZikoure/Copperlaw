/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** switch_dialogue
*/

#include "dialogues.h"

struct dialogue_s *switch_dialogue(struct dialogue_s *dialogue)
{
    dialogue->said[0] = '\0';
    sfText_setString(dialogue->text, dialogue->said);
    dialogue->n_frames = 0;
    dialogue->speed = get_text_speed();
    if (dialogue->choises) {
        change_selected_choise_color(dialogue->choises, sfWhite);
        dialogue->choises->selected = 0;
        change_selected_choise_color(dialogue->choises, sfYellow);
    }
    return dialogue->next;
}
