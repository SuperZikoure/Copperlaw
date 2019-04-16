/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** destroy_dialogue
*/

#include <stdlib.h>
#include "graph.h"
#include "dialogues.h"

void destroy_dialogue(struct dialogue_s *dialogue)
{
    free(dialogue->script);
    free(dialogue->said);
    destroy_text(dialogue->text);
    free(dialogue);
}
