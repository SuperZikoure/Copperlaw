/*
** EPITECH PROJECT, 2019
** get_all_id.c
** File description:
** get indexs of every id's locations in an int array
*/

#include "inventory.h"
#include <stdlib.h>

static int find_id(int id, inventory_t *inv)
{
    int total = 0;

    for (int i = 0; i < INV_SIZE; i++) {
        if (inv->id[i] == id)
            total++;
    }
    return (total);
}

int *get_all_id(int id, inventory_t *inv)
{
    int total = find_id(id, inv);
    int *ne_ids = malloc(sizeof(int) * total);
    int index = 0;

    if (ne_ids == NULL)
        return (NULL);
    for (int i = 0; i < INV_SIZE; i++) {
        if (inv->id[i] == id) {
            ne_ids[index] = i;
            index++;
        }
    }
    return (ne_ids);
}
