/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** get_frame_nb
*/

#include "my_rpg.h"
#include <stdio.h> 
#include "macros.h"

static sfClock *fetch_clock(int flag)
{
    static sfClock *clock = NULL;

    if (flag == -1) {
        if (clock)
            sfClock_destroy(clock);
        clock = sfClock_create();
        if (!clock)
            return NULL;
    }
    return clock;
}

static size_t compute_delta(int flag)
{
    static sfTime old = {0};
    static size_t frames = 0;
    sfTime cur;

    if (flag == -1) {
        cur = sfClock_getElapsedTime(fetch_clock(0));
        frames = (cur.microseconds - old.microseconds);
        frames /= 16666;
        old.microseconds += frames * 16666;
    }
    return frames;
}

size_t get_delta(void)
{
    return compute_delta(0);
}

void start_new_frame(void)
{
    compute_delta(-1);
}

int start_clock(void)
{
    if (!fetch_clock(-1))
        return -1;
    return 0;
}
