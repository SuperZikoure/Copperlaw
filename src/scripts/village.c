/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** intro
*/

#include "scripts.h"

const struct script_s v_can_not_buy_item[] = {
    SAY("Looks like you can't buy this...")
    END
};

const struct script_s v_barman_script[] = {
    SAY("Oh, a customer !")
    CHOSE3("You wanna have something?", "Elixir of life (3G)", "Beer (6G)",
"Other")
    CHOSE3("Maybe this?", "Rum (10G)", "Snake Venom (3G)", "Other")
    CHOSE3("What about those?", "Field Ratio (10G)", "Cactus Juice (15G)",
"Nothing actually.")
    SAY("Goodbye then.")
    END
};

const struct script_s v_blacksmith_script[] = {
    SAY("Watch me hitting this anvil.")
    END
};

const struct script_s v_sheriff_script[] = {
    SAY("There are sure no bandits in this town, mark my words.")
    SAY("Man, this donut is sure tasty...")
    END
};

const struct script_s v_cowboy_script[] = {
    SAY("Psst, I can offer you something if you want")
    CHOSE3("You won't find those elsewhere", "Tequila (30G)", "Ethanol (35G)",
"Nothing actually.")
    SAY("Goodbye then.")
    END
};

const struct script_s v_note_script[] = {
    SAY("WANTED: Nut'o Ella")
    END
};

const struct script_s v_villager_script[] = {
    SAY("Wish I had an adventurer spirit just like you!")
    END
};

const struct script_s *village_scripts[] = {
    v_barman_script,
    v_blacksmith_script,
    v_sheriff_script,
    v_note_script,
    v_cowboy_script,
    v_villager_script,
    v_can_not_buy_item,
    0
};
