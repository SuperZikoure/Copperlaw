/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** destroy_dialogue
*/

#include <stdlib.h>
#include "graph.h"
#include "dialogues.h"
#include "macros.h"

static void destroy_node(struct dialogue_s *dialogue)
{
    free(dialogue->script);
    free(dialogue->said);
    DESTROY_TEXT_FONT(dialogue->text);
    sfText_destroy(dialogue->text);
    free(dialogue);
}

static void destroy_choises(struct selection *choises)
{
    for (int i = 0; i < choises->total; i++) {
        DESTROY_TEXT_FONT(choises->texts[i]);
        sfText_destroy(choises->texts[i]);
    }
    free(choises->texts);
    free(choises);
}

void destroy_dialogue(struct dialogue_s *dialogue)
{
    struct dialogue_s *head = dialogue;

    while (head) {
        head = head->next;
        if (dialogue->choises)
            destroy_choises(dialogue->choises);
        destroy_node(dialogue);
        dialogue = head;
    }
}
