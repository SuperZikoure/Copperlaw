/*
** EPITECH PROJECT, 2019
** create_inventory.c
** File description:
** create_struct inventory_t
*/

#include "inventory.h"

inventory_t *create_inventory(void)
{
    inventory_t *inv = malloc(sizeof(inventory_t));

    if (inv == NULL)
        return (NULL);
    for (int i = 0; i < INV_SIZE; i++) {
        inv->id[i] = 0;
        inv->amount[i] = 0;
    }
    return (inv);
}
