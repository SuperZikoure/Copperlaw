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

struct dialogue_s *create_dialogue(char *script, author_t author)
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
    dialogue->text = create_text(30, (char *) dialogue_font_path);
    sfText_setPosition(dialogue->text.text, V2F(0, 0));
    sfText_setString(dialogue->text.text, dialogue->said);
    dialogue->next = NULL;
    return dialogue;
}
