/*
** EPITECH PROJECT, 2019
** test.c
** File description:
** inventory simulator
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "inventory.h"

static char *prompt(void)
{
    char *buf = NULL;
    size_t size = 0;
    int error = 0;

    error = getline(&buf, &size, stdin);
    if (error == -1)
        return (NULL);
    return (buf);
}

int simulator(void)
{
    //argv[argc * 0] = "";
    int err = 0;
    char *call = malloc(sizeof(char));
    inventory_t *inv = create_inventory();

    call[0] = '\0';
    while (my_strcmp(call, "exit") != 0 || err != -1) {
        call = prompt();
        if (call == NULL)
            return (0);
        if (strncmp(call, "add item", 8) == 0)
            err = add_item(atoi(&call[9]), inv);
        if (strncmp(call, "add stack", 9) == 0)
            err = add_stack(atoi(&call[10]), atoi(&call[12]), inv);
        if (strncmp(call, "delete item", 11) == 0)
            err = delete_item(atoi(&call[12]), inv);
        if (strncmp(call, "delete stack", 12) == 0)
            err = delete_stack(atoi(&call[13]), atoi(&call[15]), inv);
        if (strcmp(call, "show\n") == 0) {
            for (int i = 0; i < INV_SIZE; i++)
                printf("#%d# ID[%d] AMOUNT[%d] #%d#\n", i + 1, inv->id[i], inv->amount[i], i + 1);
        }
        if (strcmp(call, "clean\n") == 0)
            for (int i = 0; i < INV_SIZE; i++) {
                inv->id[i] = 0;
                inv->amount[i] = 0;
            }
    }
    return (0);
}
