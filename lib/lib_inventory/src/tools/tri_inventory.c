/*
** EPITECH PROJECT, 2019
** tri_inventory.c
** File description:
** tri the inventory placing voids at the end
*/

#include "inventory.h"

static int check_full(inventory_t *inv, int i)
{
    for (; inv->id[i] == 0 && i < INV_SIZE; i++);
    return (i);
}

static void mv_items(inventory_t *inv, int i)
{
    int ne_full = 0;

    if (inv->id[i] == 0) {
        ne_full = check_full(inv, i + 1);
        if (ne_full == INV_SIZE)
            return;
        inv->id[i] = inv->id[ne_full];
        inv->amount[i] = inv->amount[ne_full];
        inv->id[ne_full] = 0;
        inv->amount[ne_full] = 0;
    }
}

void tri_inventory(inventory_t *inv)
{
    for (int i = 0; i < INV_SIZE - 1; i++)
        mv_items(inv, i);
}
