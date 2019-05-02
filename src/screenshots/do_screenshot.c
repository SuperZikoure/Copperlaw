/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** do_screenshot
*/

#include <stdlib.h>
#include "my_string.h"
#include "my_rpg.h"

const char *extension = ".png";

static char *create_dest_path(void)
{
    char path[SCREENSHOT_FILENAME_MAX + 5] = {0};
    char c;

    for (unsigned int i = 0; i < SCREENSHOT_FILENAME_MAX; i++) {
        c = rand() % 128;
        while (!IS_ALPHA(c))
            c = rand() % 128;
        path[i] = c;
    }
    my_strcpy(path + SCREENSHOT_FILENAME_MAX, extension);
    return my_strdup(path);
}

static int save_screenshot(const sfImage *image)
{
    char *path_to_save = create_dest_path();

    if (!path_to_save)
        return -1;
    if (!sfImage_saveToFile(image, path_to_save)) {
        free(path_to_save);
        return -1;
    }
    free(path_to_save);
    return 0;
}

int do_screenshot(window_t *window)
{
    sfTexture *texture = sfTexture_create(window->width, window->height);
    sfImage *image;

    if (!texture)
        return -1;
    sfTexture_updateFromRenderWindow(texture, window->window, 0, 0);
    image = sfTexture_copyToImage(texture);
    if (save_screenshot(image) == -1)
        return -1;
    return 0;
}
