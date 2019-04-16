/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display_dialogue
*/

#include <stdio.h>
#include "my_string.h"
#include "dialogues.h"
#include "macros.h"

#define IS_TEXT_ENDED(d) STRLEN_EQ(d->script, d->said)

static void update_text_content(struct dialogue_s *dialogue)
{
    size_t len = my_strlen(dialogue->said);

    while (dialogue->script[len] == ' ' || dialogue->script[len] == '\n') {
        dialogue->said[len] = dialogue->script[len];
        len++;
    }
    dialogue->said[len] = dialogue->script[len];
    dialogue->said[len + 1] = '\0';
    sfText_setString(dialogue->text.text, dialogue->said);
}

int display_dialogue(sfRenderWindow *window, struct dialogue_s *dialogue,
                        size_t frames)
{
    sfSprite *canvas;

    if (!dialogue)
        return NO_DIALOG;
    canvas = fetch_dialogue_canvas();
    if (!canvas)
        return FAILURE;
    dialogue->n_frames += frames;
    if (IS_TEXT_ENDED(dialogue))
        dialogue->n_frames = -1;
    while (!IS_TEXT_ENDED(dialogue) &&
dialogue->n_frames >= SPEED_TO_FRAMES(dialogue->speed)) {
        dialogue->n_frames -= SPEED_TO_FRAMES(dialogue->speed);
        update_text_content(dialogue);
    }
    sfRenderWindow_drawSprite(window, canvas, NULL);
    sfRenderWindow_drawText(window, dialogue->text.text, NULL);
    return SUCCESS;
}
