/*
** EPITECH PROJECT, 2019
** inventory.h
** File description:
** header of inventory part for my_rpg
*/

#ifndef INVENTORY
#define INVENTORY

#define INV_SIZE 100
#define MAX_STACK 64

typedef struct inventory_s {
    int id[INV_SIZE];
    int amount[INV_SIZE];
} inventory_t;

/* create_inventory.c */

inventory_t *create_inventory(void);

/* add_item.c */

int add_item(int id, inventory_t inv)

#endif /*!INVENTORY */
