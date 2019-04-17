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

static char *write_script(char *str)
{
    size_t len = my_strlen(str) + 1;
    char *script = malloc(sizeof(char) * (len + len / LINE_MAX));
    size_t line_nb = 1;
    size_t j = 0;

    if (!script)
        return NULL;
    for (size_t i = 0; str[i]; i++) {
        if (i >= LINE_MAX * line_nb && str[i] == ' ') {
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

struct dialogue_s *create_dialogue_script(const struct script_s *script)
{
    struct dialogue_s *head = NULL;
    struct dialogue_s *next = NULL;
    char *script_tmp;
    size_t len = 0;

    while (script[len].script)
        len++;
    for (size_t i = len - 1; i < len; i--) {
        script_tmp = write_script(script[i].script);
        if (!script_tmp)
            return NULL;
        next = create_dialogue(script_tmp, script[i].author);
        if (!next)
            return NULL;
        next->next = head;
        head = next;
    }
    return head;
}
