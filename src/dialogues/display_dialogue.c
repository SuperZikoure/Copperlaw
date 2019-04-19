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

static int draw_dialogue(sfRenderWindow *window, struct dialogue_s *dialogue)
{
    sfSprite *canvas;

    canvas = fetch_dialogue_canvas();
    if (!canvas)
        return FAILURE;
    sfRenderWindow_drawSprite(window, canvas, NULL);
    sfRenderWindow_drawText(window, dialogue->text.text, NULL);
    if (dialogue->choises && dialogue->n_frames == -1) {
        for (int i = 0; i < dialogue->choises->total; i++)
            sfRenderWindow_drawText(window, dialogue->choises->texts[i].text,
NULL);
    }
    return SUCCESS;
}

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
    if (!dialogue)
        return NO_DIALOG;
    dialogue->n_frames += frames;
    if (IS_TEXT_ENDED(dialogue))
        dialogue->n_frames = -1;
    while (!IS_TEXT_ENDED(dialogue) &&
dialogue->n_frames >= SPEED_TO_FRAMES(dialogue->speed)) {
        dialogue->n_frames -= SPEED_TO_FRAMES(dialogue->speed);
        update_text_content(dialogue);
    }
    return draw_dialogue(window, dialogue);
}
