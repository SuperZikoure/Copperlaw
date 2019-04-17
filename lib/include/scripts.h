/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** scripts
*/

#ifndef SCRIPTS_H_
#define SCRIPTS_H_

#include "dialogues.h"

#define NEW_SCRIPT(name) const struct script_s name[]
#define EXPORT(name) extern const struct script_s name[];
#define SAY(sentence, who) {sentence, who},
#define CHOSE()
#define END {0, 0}

struct script_s {
    char *script;
    author_t author;
};

enum script_ids {
    INTRO,
    VILLAGE
};

enum author_list {
    NARRATOR,
    PLAYER,
    USR,
    PLAYER_NB
};

struct dialogue_s *create_dialogue_script(const struct script_s *script);

/* INTRO */
EXPORT(test_script_1);
EXPORT(test_script_2);

/* VILLAGE */

#endif /* !SCRIPTS_H_ */
