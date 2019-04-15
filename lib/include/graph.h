/*
** EPITECH PROJECT, 2018
** My_RPG
** File description:
** graph.h
*/

#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

typedef struct text_s
{
    sfFont *font;
    sfText *text;
} text_t;

typedef struct image_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfImage *image;
} image_t;

typedef struct anim_s
{
    int frames;
    int img;
    int speed;
    int wait;
    sfIntRect frame;
    sfVector2i size;
    image_t *sheet;
} anim_t;

typedef struct sound_s
{
    sfSound *sound;
    sfSoundBuffer *buffer;
} sound_t;

typedef struct loop_s
{
    sound_t *intro;
    sound_t *loop;
    int mode;
} loop_t;

typedef struct window_s
{
    int width;
    int height;
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
} window_t;

typedef struct keypress_s
{
    int held;
    int pressed;
    sfKeyCode key;
} keypress_t;

typedef struct input_s
{
    keypress_t *up;
    keypress_t *down;
    keypress_t *left;
    keypress_t *right;
    keypress_t *escape;
    keypress_t *space;
} input_t;

typedef struct map_s
{
    image_t *bg;
    image_t *col;
    image_t *fg;
} map_t;

/* WINDOW */

window_t *create_frame(int width, int height, char *str);
void destroy_window(window_t *window);

/* INPUT */

keypress_t *create_key(sfKeyCode key);
input_t *create_input(void);
void process_key(keypress_t *key);
void process_input(window_t *window, input_t *input);
void destroy_input(input_t *input);

/* TEXT */

text_t create_text(int fontsize, char *font);
void display_text(char *str, sfVector2f pos, text_t *text, window_t *window);
void destroy_text(text_t text);

/* IMAGE */

image_t *create_image(char *path, sfVector2f scale);
void display_image(image_t *img, sfVector2f pos, window_t *window);
void destroy_image(image_t *image);

/* ANIMATION */

anim_t *create_anim(int frames, int speed, sfVector2i size, char *sheet);
void update_anim(anim_t *anim);
void display_anim(anim_t *anim, sfVector2f pos, window_t *window);
void destroy_anim(anim_t *anim);

/* SOUND */

sound_t *create_sound(char *path);
loop_t *create_loop(char *intro_path, char *loop_path);
void destroy_sound(sound_t *sound);
void destroy_loop(loop_t *loop);

#endif