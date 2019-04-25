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
#include <stdbool.h>

typedef struct window_s
{
    int width;
    int height;
    sfVideoMode mode;
    sfRenderWindow *window;
    char *title;
    sfEvent event;
} window_t;

typedef struct text_s
{
    sfFont *font;
    sfText *text;
    window_t *window;
} text_t;

typedef struct image_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfImage *image;
    window_t *window;
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
    window_t *window;
} anim_t;

typedef struct sound_s
{
    sfSound *sound;
    sfSoundBuffer *buffer;
} sound_t;

typedef struct keypress_s
{
    int held;
    int pressed;
    sfKeyCode key;
} keypress_t;

/* WINDOW */

window_t *create_window(int size, char *str);
int change_window(window_t *window, int size, bool fullscreen);
void destroy_window(window_t *window);

/* INPUT */

keypress_t *create_key(sfKeyCode key);
void process_key(keypress_t *key);

/* TEXT */

text_t *create_text(int fontsize, char *font, window_t *window);
void display_text(char *str, sfVector2f pos, text_t *text);
void destroy_text(text_t *text);
/* quick sfText creator */
sfText *quick_text_create(unsigned int char_size, const char *fontpath);

/* IMAGE */

image_t *create_image(const char *path, window_t *window);
void display_image(image_t *img, sfVector2f pos);
void destroy_image(image_t *image);

/* ANIMATION */

anim_t *create_anim(sfVector2f fps, sfVector2i size, char *path, window_t *wd);
void update_anim(anim_t *anim);
void display_anim(anim_t *anim, sfVector2f pos);
void destroy_anim(anim_t *anim);

/* SOUND */

sound_t *create_sound(char *path);
void destroy_sound(sound_t *sound);

#endif