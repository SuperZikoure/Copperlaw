/*
** EPITECH PROJECT, 2019
** get_amount.c
** File description:
** get the amount of an id in the inventory
*/

#include "inventory.h"

static int find_id(int id, inventory_t *inv)
{
    int total = 0;

    for (int i = 0; i < INV_SIZE; i++) {
        if (inv->id[i] == id)
            total++;
    }
    return (total);
}

int get_amount(int id, inventory_t *inv)
{
    int find = find_id(id, inv);
    int *index = get_all_id(id, inv);
    int total_amount = 0;

    for (int i = 0; i < find; i++)
        total_amount += AMOUNT_IDX(index[i], inv);
    return (total_amount);
}
