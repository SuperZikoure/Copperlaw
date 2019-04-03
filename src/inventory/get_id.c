/*
** EPITECH PROJECT, 2019
** get_id.c
** File description:
** get the id of an item in the inventory
*/

#include "inventory.h"

int get_id_free(int id, inventory_t *inv)
{
    for (int i = 0; i < INV_SIZE; i++) {
        if (inv->id[i] == id && inv->amount[i] < MAX_STACK)
            return (i);
    }
    return (-1);
}

int get_id(int id, inventory_t *inv)
{
    for (int i = 0; i < INV_SIZE; i++) {
        if (inv->id[i] == id)
            return (i);
    }
    return (-1);
}
