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

#define EXPORT(name) extern const struct script_s *name[];
#define SAY(sentence) {sentence, 0, {0}, USR},
#define CHOSE1(sentence, c1) {sentence, 1, {c1, 0}, USR},
#define CHOSE2(sentence, c1, c2) {sentence, 2, {c1, c2, 0}, USR},
#define CHOSE3(sentence, c1, c2, c3) {sentence, 3, {c1, c2, c3, 0}, USR},
#define END {0, 0, {0}, 0}

struct script_s {
    char *script;
    size_t choise_nb;
    char *choise[MAX_CHOSE];
    author_t author;
};

enum author_list {
    NARRATOR,
    PLAYER1,
    USR,
    AUTHOR_NB
};

struct dialogue_s *create_dialogue_from_script(const struct script_s *script);

/* SCRIPTS */
EXPORT(intro_scripts)
EXPORT(village_scripts)
EXPORT(weapon_scripts)
extern const struct script_s **script_list[];

#endif /* !SCRIPTS_H_ */
