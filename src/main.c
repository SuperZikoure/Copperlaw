/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main function
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "dialogues.h"

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
                    if (event.key.code == sfKeySpace) {
                        if (dialogue->n_frames == -1) {
                            dialogue->said[0] = '\0';
                            sfText_setString(dialogue->text.text, dialogue->said);
                            dialogue->n_frames = 0;
                            dialogue->speed = get_text_speed();
                            dialogue = dialogue->next;
                        } else
                            dialogue->speed = INSTANT;
                    }
                } else if (event.key.code == sfKeyE) {
                    dialogue = fetch_dialogue_script(0);
                }
            }
        }
        sfRenderWindow_clear(window, sfBlue);
        display_dialogue(window, dialogue, 1);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return (0);
}
