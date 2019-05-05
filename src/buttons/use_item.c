/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** item_buttons
*/

#include "my_rpg.h"
#include "macros.h"

const item_function_t item_uses[] = {
    use_elixir,
    use_beer,
    use_rum,
    use_snakevenom,
    use_fieldratio,
    use_cactusjuice,
    use_tequila,
    use_ethanol
};

int use_item(game_t *game, int option)
{
    if (get_amount(option, G_INVENTORY) == 0)
        return 0;
    delete_item(option, G_INVENTORY);
    item_uses[option - 1](game);
    return 0;
}
