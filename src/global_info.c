/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** info.c
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "graph.h"
#include "my_rpg.h"

static const sfVideoMode window_size[6] = {
    {640, 360, 32},
    {800, 450, 32},
    {1024, 576, 32},
    {1280, 720, 32},
    {1600, 900, 32},
    {1920, 1080, 32}
};