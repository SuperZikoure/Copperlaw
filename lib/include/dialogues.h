/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** dialogues
*/

#ifndef DIALOGUES_H_
#define DIALOGUES_H_

#include <SFML/Graphics.h>
#include "graph.h"

#define CHARS_MAX

enum text_speed {
    NORMAL,
    SLOW,
    FAST,
    INSTANT,
    TEXT_SPEED_MAX
};

enum text_mode {
    BASIC,
    NARRATIVE,
    EXCLAMATION,
    THINKING,
    MODE_MAX
};

typedef unsigned int author_id_t;

struct dialogue_s {
    char *script;
    size_t n_wrote;
    author_id_t author;
    enum text_speed speed;
    enum text_mode mode;
    text_t text;
};

struct dialogue_script_s {
    struct dialogue_s *script;
};

/*
struct avec le fond (ou tableau de fonds)
liste totale des dialogues
*/

#endif /* !DIALOGUES_H_ */
