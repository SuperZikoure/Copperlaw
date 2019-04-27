/*
** EPITECH PROJECT, 2019
** stack_item.c
** File description:
** stack item in a case of the inventory
*/

#include "inventory.h"

int stack_item(int index, inventory_t *inv)
{
    if (inv->amount[index] < MAX_STACK) {
        inv->amount[index]++;
        return (0);
    }
    return (-1);
}
