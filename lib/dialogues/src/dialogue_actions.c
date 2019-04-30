/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** dialogue_list
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "dialogues.h"
#include "scripts.h"

static struct dialogue_s **fetch_current_scipt_scene(int index,
                                                enum zone_ids id)
{
    static struct dialogue_s **ptr = NULL;

    if (index == -2)
        ptr = NULL;
    if (index == -1) {
        ptr = load_scene_dialogues(id);
        index = 0;
    }
    if (!ptr)
        return NULL;
    return &ptr[index];
}

struct dialogue_s *get_dialogue(int index)
{
    return *fetch_current_scipt_scene(index, 0);
}

int load_dialogue_scene(enum zone_ids id)
{
    struct dialogue_s **ptr = fetch_current_scipt_scene(-1, id);

    if (!ptr)
        return -1;
    return 0;
}

void destroy_current_dialogue_script(void)
{
    struct dialogue_s **ptr = fetch_current_scipt_scene(0, 0);

    if (!ptr)
        return;
    for (size_t i = 0; ptr[i]; i++)
        destroy_dialogue(ptr[i]);
    free(ptr);
    fetch_current_scipt_scene(-2, 0);
}
