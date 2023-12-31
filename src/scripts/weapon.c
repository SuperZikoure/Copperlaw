/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** intro
*/

#include "scripts.h"

const struct script_s w_barman_script[] = {
    SAY("Burp.")
    END
};

const struct script_s w_blacksmith_script[] = {
    SAY("Hey stranger, want a weapon?")
    CHOSE2("Best I can offer is a revolver or a shotgun. What do you want ?",
"Revolver", "Shotgun")
    END
};

const struct script_s w_sheriff_script[] = {
    SAY("Hello there. How life going ?")
    END
};

const struct script_s w_cowboy_script[] = {
    SAY("Act like you didn't see me.")
    END
};

const struct script_s w_note_script[] = {
    SAY("WANTED: Nut'o Ella")
    END
};

const struct script_s w_villager_script[] = {
    SAY("Oh so you need a weapon, huh ?")
    SAY("Since you've got some money, why not go ask the blacksmith?")
    END
};

const struct script_s *weapon_scripts[] = {
    w_barman_script,
    w_blacksmith_script,
    w_sheriff_script,
    w_note_script,
    w_cowboy_script,
    w_villager_script,
    0
};
