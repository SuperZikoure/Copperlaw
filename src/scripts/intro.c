/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** intro
*/

#include "scripts.h"

const struct script_s blank_aha[] = {
    SAY("...", NARRATOR)
    END
};

const struct script_s test_script_1[] = {
    SAY("Whoa je veux une pomme.", PLAYER1)
    SAY("eh beh bas moi j'en ai des bonnes", USR)
    SAY("oh oui ! je veux.", PLAYER1)
    CHOSE2("c'est 2 gold la pomme tu la veux oui ou non ?", "oui", "non", USR)
    END
};

const struct script_s test_script_2[] = {
    SAY("le nutella c'est bon 0", NARRATOR)
    SAY("Alors j'ai supprime des lignes psk c'etait chiant pour test a chaque fois ...", NARRATOR)
    CHOSE3("le nutella c'est quoi a ton avis ???????  le nutella c'est bon 1 le nutella c'est bon 1 le nutella c'est bon 1nu t e l l a nu te l l anutella",
"Super mega bon tu peux pas test mon gars1",
"Super mega bon tu peux pas test mon gars2",
"Super mega bon tu peux pas test mon gars3", NARRATOR)
    END
};

const struct script_s test[] = {
    SAY("Ceci est un test.", PLAYER1)
    SAY("haha yes.", PLAYER1)
    END
};

const struct script_s *intro_scripts[] = {
    test_script_1,
    test_script_2,
    test,
    0
};
