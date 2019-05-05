/*
** EPITECH PROJECT, 2019
** inventory.h
** File description:
** header of inventory part for my_rpg
*/

#ifndef __INVENTORY__
#define __INVENTORY__

#define INV_SIZE 8
#define MAX_STACK 99

typedef struct inventory_s {
    int id[INV_SIZE];
    int amount[INV_SIZE];
    int tmp_id;
    int tmp_amount;
} inventory_t;

/* defined functions */

#define AMOUNT_IDX(index, inv) (inv->amount[index])
#define ID_IDX(index, inv) (inv->id[index])

/*
** Every functions return -1 if the function failed
** You probably don't need to use functions in the tools dir
*/

/* create_inventory.c */

inventory_t *create_inventory(void);

/* add_item.c */

int add_item(int id, inventory_t *inv);
int add_stack(int id, int amount, inventory_t *inv);

/* add_item_with_index.c */

int add_item_with_index(int id, int i, inventory_t *inv);
int add_stack_with_index(int id, int amount, int i, inventory_t *inv);

/* remplace_item.c */

int remplace_item(int id, inventory_t *inv);

/* remplace_item_with_index.c */

int remplace_item_with_index(int i, inventory_t *inv);

/* delete_item.c */

int delete_item(int id, inventory_t *inv);
int delete_stack(int id, int amount, inventory_t *inv);

/* delete_item_with_index.c */

int delete_item_with_index(int index, inventory_t *inv);
int delete_stack_with_index(int index, int amount, inventory_t *inv);

/* get_amount.c */

int get_amount(int id, inventory_t *inv);

/* tools/get_id.c */

int get_id_free(int id, inventory_t *inv);
int get_id(int id, inventory_t *inv);
int get_id_last(int id, inventory_t *inv);

/* tools/flood_inventory.c */

int flood_inventory(int id, inventory_t *inv);

/* tools/add_in_new_stack.c */

int add_in_new_stack(int id, int index, inventory_t *inv);

/* tools/stack_item.c */

int stack_item(int index, inventory_t *inv);

/* tools/check_index.c */

int check_index(int index);

/* tools/get_all_id.c */

int *get_all_id(int id, inventory_t *inv);

/* tools/tri_inventory.c */

void tri_inventory(inventory_t *inv);

#endif /*!__INVENTORY__ */
