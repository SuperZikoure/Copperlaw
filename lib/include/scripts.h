/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** scripts
*/

#ifndef SCRIPTS_H_
#define SCRIPTS_H_

#include "dialogues.h"

#define MAX_CHOSE 4

#define NEW_SCRIPT(name) const struct script_s name[]
#define EXPORT(name) extern const struct script_s name[];
#define SAY(sentence, who) {sentence, 0, {0}, who},
#define CHOSE1(sentence, c1, who) {sentence, 1, {c1, 0}, who},
#define CHOSE2(sentence, c1, c2, who) {sentence, 2, {c1, c2, 0}, who},
#define CHOSE3(sentence, c1, c2, c3, who) {sentence, 3, {c1, c2, c3, 0}, who},
#define END {0, 0, {0}, 0}

struct script_s {
    char *script;
    size_t choise_nb;
    char *choise[MAX_CHOSE];
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
