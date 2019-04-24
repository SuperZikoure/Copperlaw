/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** dialogues
*/

#ifndef DIALOGUES_H_
#define DIALOGUES_H_

#include <SFML/Graphics.h>
#include "rpg.h"
#include "graph.h"

#define FAILURE -1
#define SUCCESS 0
#define NO_DIALOG 400

#define LINE_MAX 50
#define CHOISE_MAX 15

extern const char *dialogue_font_path;
extern const char *texture_path;

enum text_speed {
    INSTANT,
    FAST,
    NORMAL,
    SLOW,
    SPEED_MAX
};
enum text_speed get_text_speed(void);
void change_text_speed(int modifier);
#define SPEED_TO_FRAMES(s) (int) s + (int) s - 1

typedef unsigned int author_t;

struct selection {
    int total;
    int selected;
    sfText **texts;
};

struct dialogue_s {
    char *script;
    char *said;
    long n_frames;
    author_t author;
    enum text_speed speed;
    sfText *text;
    struct selection *choises;
    struct dialogue_s *next;
};

/* function called in the game loop */
int display_dialogue(window_t *window, struct dialogue_s *dialogue,
                        size_t frames);

/* Dialogue structure */
struct dialogue_s *create_dialogue(char *script, author_t author,
                                    struct selection *choises);
void destroy_dialogue(struct dialogue_s *dialogue);

/* Dialogue canvas */
sfSprite *fetch_dialogue_canvas(void);
void destroy_dialogue_canvas(void);

/* Dialogue actions */
struct dialogue_s *get_dialogue(int index);
struct dialogue_s **load_scene_dialogues(enum zone_ids id);
int load_dialogue_scene(enum zone_ids id);
void destroy_current_dialogue_script(void);

#endif /* !DIALOGUES_H_ */
