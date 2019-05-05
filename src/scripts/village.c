/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** intro
*/

#include "scripts.h"

const struct script_s v_barman_script[] = {
    SAY("Oh, a customer !")
    CHOSE3("You wanna have something?", "Elixir of life", "Beer", "Other")
    CHOSE3("Maybe this?", "Rum", "Snake Venom", "Other")
    CHOSE3("What about those?", "Field Ratio", "Cactus Juice",
"Nothing actually.")
    SAY("Goodbye then.")
    END
};

const struct script_s v_blacksmith_script[] = {
    SAY("Watch me hitting this sword.")
    END
};

const struct script_s v_sheriff_script[] = {
    SAY("There are sure no bandits in this town.")
    SAY("Mark my words.")
    END
};

const struct script_s v_cowboy_script[] = {
    SAY("3")
    END
};

const struct script_s v_note_script[] = {
    SAY("WANTED: Nut'o Ella")
    END
};

const struct script_s v_villager_script[] = {
    SAY("3")
    END
};

const struct script_s *village_scripts[] = {
    v_barman_script,
    v_blacksmith_script,
    v_sheriff_script,
    v_note_script,
    v_cowboy_script,
    v_villager_script,
    0
};
