/*
** EPITECH PROJECT, 2019
** add_stack_with_index.c
** File description:
** all tests for add_stack_with_index function
*/

#include <criterion/criterion.h>
#include "inventory.h"
#include <stdio.h>

/*
* Test add_stack_with_index(int id, int amount, int i, inventory_t *inv)
* #define INV_SIZE = 100 &&
* #define MAX_STACK = 64 to build tests
*/

Test(add_stack_with_index, add_a_stack_in_an_empty_inventory)
{
    inventory_t *inv = create_inventory();
    int item_id = 1600;
    int index = 10;
    int amount = 50;
    int error = add_stack_with_index(item_id, amount, index, inv);

    cr_assert_eq(error, 0);
    cr_assert_eq(inv->id[10], 1600);
    cr_assert_eq(inv->amount[10], 50);
}

Test(add_stack_with_index, add_a_stack_in_an_inventory_semi_full)
{
    inventory_t *inv = create_inventory();
    int item_id = 1600;
    int amount = 10;
    int index = 0;
    int error;

    inv->id[0] = 1598;
    inv->amount[0] = 1;
    inv->id[1] = 1599;
    inv->amount[1] = 2;
    error = add_stack_with_index(item_id, amount, index, inv);
    cr_assert_eq(error, 0);
    cr_assert_eq(inv->id[2], 1600);
    cr_assert_eq(inv->amount[2], 10);
}

Test(add_stack_with_index, add_a_stack_in_a_stack)
{
    inventory_t *inv = create_inventory();
    int item_id = 1600;
    int amount = 11;
    int index = 0;
    int error;

    inv->id[0] = 1600;
    inv->amount[0] = 9;
    error = add_stack_with_index(item_id, amount, index, inv);
    cr_assert_eq(error, 0);
    cr_assert_eq(inv->id[0], 1600);
    cr_assert_eq(inv->amount[0], 20);
}

Test(add_stack_with_index, add_to_big_stack_to_another)
{
    inventory_t *inv = create_inventory();
    int item_id = 1600;
    int amount = 60;
    int index = 0;
    int error;

    inv->id[0] = 1600;
    inv->amount[0] = 5;
    error = add_stack_with_index(item_id, amount, index, inv);
    cr_assert_eq(error, 0);
    cr_assert_eq(inv->id[0], 1600);
    cr_assert_eq(inv->amount[0], 64);
    cr_assert_eq(inv->id[1], 1600);
    cr_assert_eq(inv->amount[1], 1);
}
