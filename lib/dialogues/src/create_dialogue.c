/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create_dialogue
*/

#include <stdlib.h>
#include <string.h>
#include "my_string.h"
#include "dialogues.h"
#include "macros.h"

struct dialogue_s *create_dialogue(char *script, author_t author,
                                    struct selection *choises)
{
    struct dialogue_s *dialogue = malloc(sizeof(struct dialogue_s));
    size_t len = my_strlen(script) + 1;
    char *said = malloc(sizeof(char) * len);

    if (!said || !dialogue)
        return NULL;
    said[0] = '\0';
    dialogue->script = script;
    dialogue->said = said;
    dialogue->n_frames = 0;
    dialogue->author = author;
    dialogue->speed = get_text_speed();
    dialogue->text = quick_text_create(30, dialogue_font_path);
    if (!dialogue->text)
        return NULL;
    sfText_setScale(dialogue->text, V2F(.45, .45));
    sfText_setString(dialogue->text, dialogue->said);
    dialogue->choises = choises;
    dialogue->next = NULL;
    return dialogue;
}
