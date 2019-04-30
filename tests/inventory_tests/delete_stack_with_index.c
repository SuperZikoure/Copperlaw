/*
** EPITECH PROJECT, 2019
** delete_stack_with_index.c
** File description:
** all tests for delete_stack_with_index function
*/

#include <criterion/criterion.h>
#include "inventory.h"
#include <stdio.h>

/*
* Test delete_stack_with_index(int index, int amount, inventory_t *inv)
* #define INV_SIZE = 100 &&
* #define MAX_STACK = 64 to build tests
*/

Test(delete_stack_with_index, in_an_inventory_fulled_with_same_id)
{
    inventory_t *inv = create_inventory();
    int amount = 32;
    int error;

    flood_inventory(1600, inv);
    error = delete_stack_with_index(10, amount, inv);
    cr_assert_eq(error, 0);
    cr_assert_eq(inv->id[10], 1600);
    cr_assert_eq(inv->amount[10], 32);
}

Test(delete_stack_with_index, stack_bigger_than_max_stack)
{
    inventory_t *inv = create_inventory();
    int item_id = 1600;
    int amount = 65;
    int error;

    flood_inventory(1600, inv);
    error = delete_stack_with_index(item_id, amount, inv);
    cr_assert_eq(error, -1);
}

Test(delete_stack_with_index, wrong_index)
{
    inventory_t *inv = create_inventory();
    int amount = 2;
    int error;

    flood_inventory(1, inv);
    error = delete_stack_with_index(-2, amount, inv);
    cr_assert_eq(error, -1);
}
