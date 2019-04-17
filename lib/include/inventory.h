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

#endif /*!INVENTORY */

/* CREATE_INVENTORY       my_rpg Programmer's Manual       CREATE_INVENTORY */
/*                                                                          */
/* NAME                                                                     */
/*     create_inventory - create a pointer to a new inventory structure     */
/*     filled with 0                                                        */
/*                                                                          */
/* RETURN VALUE                                                             */
/*     The function return a pointer to an inventory_t struct or NULL if    */
/*     an error has occurred                                                */
/*                                                                          */
/* my_rpg                      2019-04-01                  CREATE_INVENTORY */

/* ADD_ITEM                my_rpg Programmer's Manual              ADD_ITEM */
/*                                                                          */
/* NAME                                                                     */
/*     add_item - add an item to the inventory struct or stack it           */
/*                                                                          */
/* RETURN VALUE                                                             */
/*     The function return 0 if the item is correctly stacked else the      */
/*     function return -1 if there is no more places in the inventory       */
/*     (in this case the item will be placed in tmp part of the struct)     */
/*     and -2 if the inventory size is negative                             */
/* my_rpg                      2019-04-01                          ADD_ITEM */

/* ADD_STACK               my_rpg Programmer's Manual             ADD_STACK */
/*                                                                          */
/* NAME                                                                     */
/*     add_stack - add a stack of items to the inventory struct             */
/*                                                                          */
/* RETURN VALUE                                                             */
/*     The function return 0 if the stack is correctly set else the function*/
/*     return -1 if there is no more places in the inventory (in this case  */
/*     the stack will be placed in tmp part of the struct) and -2 if the    */
/*     inventory size is negative                                           */
/* my_rpg                      2019-04-01                          ADD_ITEM */
