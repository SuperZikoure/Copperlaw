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

const char *script_paths[] = {
    "src/dialogues/scripts/intro"
};

static struct dialogue_s **create_scene_dialogues()
{
    struct dialogue_s **ptr = NULL;
    // scene_t id = get_current_scene_id();

    ptr = malloc(sizeof(struct dialogue_s *) * 3);
    ptr[0] = create_dialogue_script(test_script_1);
    ptr[1] = create_dialogue_script(test_script_2);
    ptr[2] = NULL;
    return ptr;
}

struct dialogue_s *fetch_dialogue_script(int index)
{
    static struct dialogue_s **ptr = NULL;

    if (!ptr) {
        ptr = create_scene_dialogues();
        if (!ptr)
            return NULL;
    }
    return ptr[index];
}

void destroy_dialogue_script(void)
{
    struct dialogue_s *tmp = fetch_dialogue_script(0);
    struct dialogue_s **ptr = &tmp;

    for (size_t i = 0; ptr[i]; i++)
        destroy_dialogue(ptr[i]);
    free(ptr);
}
