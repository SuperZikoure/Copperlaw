/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create_dialogue_script
*/

#include <stdlib.h>
#include <string.h>
#include "my_string.h"
#include "dialogues.h"
#include "scripts.h"
#include "macros.h"

static char *write_script(char *str, int line_max)
{
    size_t len = my_strlen(str) + 1;
    char *script = malloc(sizeof(char) * (len + len / line_max));
    size_t line_nb = 1;
    size_t j = 0;

    if (!script)
        return NULL;
    for (size_t i = 0; str[i]; i++) {
        if (i >= line_max * line_nb && str[i] == ' ') {
            script[j++] = '\n';
            line_nb++;
            continue;
        }
        script[j] = str[i];
        j++;
    }
    script[j] = '\0';
    return script;
}

static struct selection *init_choises(struct script_s *script)
{
    struct selection *choises = malloc(sizeof(struct selection));
    sfText **text_array = malloc(sizeof(sfText *) * script->choise_nb);
    char *choise_tmp;

    if (!choises || !text_array)
        return NULL;
    choises->total = script->choise_nb;
    choises->selected = 0;
    for (int i = 0; i < choises->total; i++) {
        text_array[i] = quick_text_create(25, dialogue_font_path);
        if (!text_array[i])
            return NULL;
        sfText_setScale(text_array[i], V2F(.40, .40));
        choise_tmp = write_script(script->choise[i], CHOISE_MAX);
        if (!choise_tmp)
            return NULL;
        sfText_setString(text_array[i], choise_tmp);
    }
    sfText_setColor(text_array[choises->selected], sfYellow);
    choises->texts = text_array;
    return choises;
}

static struct dialogue_s *create_dialogue_script(struct script_s *script)
{
    struct selection *choises = NULL;
    char *script_tmp;

    script_tmp = write_script(script->script, LINE_MAX);
    if (!script_tmp)
        return NULL;
    if (script->choise_nb) {
        choises = init_choises(script);
        if (!choises)
            return NULL;
    }
    return create_dialogue(script_tmp, script->author, choises);
}

struct dialogue_s *create_dialogue_from_script(const struct script_s *script)
{
    struct dialogue_s *head = NULL;
    struct dialogue_s *next = NULL;
    size_t len = 0;

    while (script[len].script)
        len++;
    for (size_t i = len - 1; i < len; i--) {
        next = create_dialogue_script((struct script_s *) &script[i]);
        if (!next)
            return NULL;
        next->next = head;
        head = next;
    }
    return head;
}
