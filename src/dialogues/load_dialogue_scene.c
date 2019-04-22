/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create_dialogue_scene
*/

#include <stdlib.h>
#include "my_string.h"
#include "scripts.h"

const struct script_s **script_list[] = {
    intro_scripts,
    village_scripts,
};

struct dialogue_s **load_scene_dialogues(enum zone_ids id)
{
    struct dialogue_s **ptr;
    size_t len = my_arraylen((void **) script_list[id]);

    ptr = malloc(sizeof(struct dialogue_s *) * (len + 1));
    if (!ptr)
        return NULL;
    for (size_t i = 0; i < len; i++) {
        ptr[i] = create_dialogue_from_script(script_list[id][i]);
        if (!ptr[i])
            return NULL;
    }
    ptr[len] = NULL;
    return ptr;
}
