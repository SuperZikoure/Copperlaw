/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** intro
*/

#include "scripts.h"

NEW_SCRIPT(aze) = {
    {"oui", 1}
};

NEW_SCRIPT(test_script_1) = {
    SAY("Whoa je veux une pomme.", PLAYER)
    SAY("eh bé bas moi j'en ai des bonnes", USR)
    SAY("oh oui ! je veux.", PLAYER)
    SAY("c'est 2 gold la pomme tu la veux oui ou non ?", USR)
    END
};

NEW_SCRIPT(test_script_2) = {
    SAY("Whoa il fait tellement chaud !", PLAYER)
    END
};
