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
#define TEXT_ENDED 402

#define LINE_MAX 50

enum text_speed {
    INSTANT, // 0
    FAST, // 1
    NORMAL, // 3
    SLOW, // 5
    SPEED_MAX
};
enum text_speed get_text_speed(void);
void change_text_speed(int modifier);

enum script_ids {
    INTRO
};

// enum text_mode {BASIC, NARRATIVE, EXCLAMATION, THINKING, MODE_MAX};

typedef unsigned int scene_t;
typedef unsigned int author_t;

struct dialogue_s {
    char *script;
    char *said;
    long n_frames;
    author_t author;
    enum text_speed speed;
    text_t text;
    struct dialogue_s *next;
};

int display_dialogue(sfRenderWindow *window, struct dialogue_s *dialogue,
                        size_t frames);

struct dialogue_s *create_dialogue(char *script, author_t author);
struct dialogue_s *create_dialogue_script(void);
void destroy_dialogue(struct dialogue_s *dialogue);

/* Dialogue canvas */
sfSprite *fetch_dialogue_canvas(void);
void destroy_dialogue_canvas(void);

/* Dialogue scripts */
struct dialogue_s *fetch_dialogue_script(int index);
void destroy_dialogue_script(void);

#endif /* !DIALOGUES_H_ */
