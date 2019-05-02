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

const sfVector2f canvas_pos = {60, 255};
const sfVector2f dia_pos = {100, 275};

static int draw_dialogue(game_t *game, struct dialogue_s *dialogue)
{
    sfSprite *canvas;

    canvas = fetch_dialogue_canvas();
    if (!canvas)
        return FAILURE;
    sfSprite_setPosition(canvas, global_to_view(canvas_pos, game->view));
    sfText_setPosition(dialogue->text, global_to_view(dia_pos, game->view));
    sfRenderWindow_drawSprite(WINDOW->window, canvas, NULL);
    sfRenderWindow_drawText(WINDOW->window, dialogue->text, NULL);
    if (dialogue->choises && dialogue->n_frames == -1) {
        for (int i = 0; i < dialogue->choises->total; i++) {
            sfText_setPosition(dialogue->choises->texts[i],
global_to_view(V2F(95 + 200 * i, 340), VIEW));
            sfRenderWindow_drawText(WINDOW->window, dialogue->choises->texts[i],
NULL);
        }
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
    sfText_setString(dialogue->text, dialogue->said);
}

int display_dialogue(game_t *game, struct dialogue_s *dialogue,
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
    return draw_dialogue(game, dialogue);
}
