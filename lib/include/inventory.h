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
    int tmp_id;
    int tmp_amount;
} inventory_t;

/*
 * Every functions return 0 on success and -1 if the function failed
 */

/* create_inventory.c */

inventory_t *create_inventory(void);

/* add_item.c */

int add_item(int id, inventory_t *inv);
int add_stack(int id, int amount, inventory_t *inv);

/* remplace_item.c */

int remplace_item(int id, inventory_t *inv);

/* delete_item.c */

int delete_item(int id, inventory_t *inv);
int delete_stack(int id, int amount, inventory_t *inv);

/* get_id.c */

int get_id_free(int id, inventory_t *inv);
int get_id(int id, inventory_t *inv);

/* flood_inventory.c */

int flood_inventory(int id, inventory_t *inv);

#endif /*!INVENTORY */
