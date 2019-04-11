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

#define FAILURE -1
#define SUCCESS 0
#define NO_DIALOG 401
#define CHARS_MAX 50

enum text_speed {NORMAL, SLOW, FAST, INSTANT, TEXT_SPEED_MAX};
enum text_mode {BASIC, NARRATIVE, EXCLAMATION, THINKING, MODE_MAX};

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

/* Dialogue canvas */
sfSprite *fetch_dialogue_canvas(void);
void destroy_dialogue_canvas(void);

#endif /* !DIALOGUES_H_ */
