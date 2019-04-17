/*
** EPITECH PROJECT, 2019
** flood_inventory.c
** File description:
** function that flood the inventory (used to test)
*/

#include "inventory.h"

int flood_inventory(int id, inventory_t *inv)
{
    for (int i = 0; i < INV_SIZE; i++) {
        inv->id[i] = id;
        inv->amount[i] = MAX_STACK;
    }
    return (0);
}
