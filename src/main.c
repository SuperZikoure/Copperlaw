/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main function
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "dialogues.h"
#include "macros.h"

struct dialogue_s *switch_dialogue(struct dialogue_s *dialogue)
{
    dialogue->said[0] = '\0';
    sfText_setString(dialogue->text.text, dialogue->said);
    dialogue->n_frames = 0;
    dialogue->speed = get_text_speed();
    if (dialogue->choises) {
        SET_SELECTED_CHOISE_COLOR(dialogue->choises, sfWhite);
        dialogue->choises->selected = 0;
        SET_SELECTED_CHOISE_COLOR(dialogue->choises, sfYellow);
    }
    return dialogue->next;
}

int main(void)
{
    sfVideoMode vidmode = {1600, 900, 32};
    sfRenderWindow *window = sfRenderWindow_create(vidmode, "Dialogues", sfDefaultStyle, NULL);
    sfEvent event;
    struct dialogue_s *dialogue = NULL;

    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_display(window);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtKeyPressed) {
                if (event.key.code == sfKeyEscape)
                    sfRenderWindow_close(window);
                if (dialogue) {
                    if (dialogue->choises && dialogue->n_frames == -1) {
                        if (event.key.code == sfKeyReturn) {
                            printf("'%s' [%d]\n", sfText_getString(dialogue->choises->texts[dialogue->choises->selected].text), dialogue->choises->selected);
                            dialogue = switch_dialogue(dialogue);
                        }
                        if (event.key.code == sfKeyLeft && dialogue->choises->selected > 0) {
                            SET_SELECTED_CHOISE_COLOR(dialogue->choises, sfWhite);
                            dialogue->choises->selected--;
                            SET_SELECTED_CHOISE_COLOR(dialogue->choises, sfYellow);
                        }
                        if (event.key.code == sfKeyRight && dialogue->choises->selected < dialogue->choises->total - 1) {
                            SET_SELECTED_CHOISE_COLOR(dialogue->choises, sfWhite);
                            dialogue->choises->selected++;
                            SET_SELECTED_CHOISE_COLOR(dialogue->choises, sfYellow);
                        }
                    } else {
                        if (event.key.code == sfKeySpace) {
                            if (dialogue->n_frames == -1)
                                dialogue = switch_dialogue(dialogue);
                            else
                                dialogue->speed = INSTANT;
                        }
                    }
                } else if (event.key.code == sfKeyE)
                    dialogue = fetch_dialogue_script(0);
                else if (event.key.code == sfKeyR)
                    dialogue = fetch_dialogue_script(1);
            }
        }
        sfRenderWindow_clear(window, sfBlue);
        display_dialogue(window, dialogue, 1);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return (0);
}
