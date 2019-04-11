/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display_dialogue
*/

#include "dialogues.h"
#include "macros.h"

int display_dialogue(void)
{
    sfSprite *canvas;

    // if (no dialogues)
        // return NO_DIALOG;
    canvas = fetch_dialogue_canvas();
    if (!canvas)
        return FAILURE;
    
    return SUCCESS;
}
