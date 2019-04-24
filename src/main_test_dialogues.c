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
    sfText_setString(dialogue->text, dialogue->said);
    dialogue->n_frames = 0;
    dialogue->speed = get_text_speed();
    if (dialogue->choises) {
        SET_SELECTED_CHOISE_COLOR(dialogue->choises, sfWhite);
        dialogue->choises->selected = 0;
        SET_SELECTED_CHOISE_COLOR(dialogue->choises, sfYellow);
    }
    return dialogue->next;
}

enum zone_ids get_current_scene_id(int action)
{
    static enum zone_ids id = INTRO;

    if (action == 0)
        return id;
    id = id == INTRO ? VILLAGE : INTRO;
    return id;
}

int main_test_dialogues(void)
{
    window_t *window = create_window(5, "CopperLaw");
    sfEvent event;
    struct dialogue_s *dialogue = NULL;

    if (load_dialogue_scene(get_current_scene_id(0)) == -1)
        return 84;
    sfRenderWindow_setFramerateLimit(window->window, 60);
    sfRenderWindow_display(window->window);
    while (sfRenderWindow_isOpen(window->window)) {
        while (sfRenderWindow_pollEvent(window->window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window->window);
            if (event.type == sfEvtKeyPressed) {
                if (event.key.code == sfKeyEscape)
                    sfRenderWindow_close(window->window);
                if (dialogue) {
                    if (dialogue->choises && dialogue->n_frames == -1) {
                        if (event.key.code == sfKeyReturn) {
                            printf("'%s' [%d]\n", sfText_getString(dialogue->choises->texts[dialogue->choises->selected]), dialogue->choises->selected);
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
                    dialogue = get_dialogue(0);
                else if (event.key.code == sfKeyR)
                    dialogue = get_dialogue(1);
                else if (event.key.code == sfKeyC) {
                    destroy_current_dialogue_script();
                    if (load_dialogue_scene(get_current_scene_id(1)) == -1)
                        return 84;
                }
            }
        }
        sfRenderWindow_clear(window->window, sfBlue);
        display_dialogue(window, dialogue, 1);
        sfRenderWindow_display(window->window);
    }
    destroy_current_dialogue_script();
    sfRenderWindow_destroy(window->window);
    return (0);
}
