/*
** EPITECH PROJECT, 2022
** hun
** File description:
** ter
*/

#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <time.h>
#include <stdbool.h>
#include <SFML/System/Clock.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics/Rect.h>
#include "struct.h"
#include "include/my.h"

struct bird fctevent(struct bird newbird, sfRenderWindow *window)
{
    sfEvent event;
    sfVector2i pos_mouse;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            pos_mouse = sfMouse_getPosition(window);
            newbird = comparemouse(newbird, pos_mouse);
        }
    }
    return newbird;
}

int wind(void)
{
    sfRenderWindow *w; sfVideoMode v = {1920, 1080, 32};
    sfClock *j = sfClock_create(); sfClock *k = sfClock_create();
    sfTexture *t = sfTexture_createFromFile("c.jpg", NULL);
    sfSprite *s = sfSprite_create(); sfTime t1, h;struct bird z;
    z = createbird(); sfVector2f scale = {1.351, 1.24};
    sfSprite_setScale(s, scale); sfSprite_setTexture(s, t, sfTrue);
    w = sfRenderWindow_create(v, "htr", sfResize | sfClose, NULL);
    sfWindow_setFramerateLimit(w, 60);
    while (sfRenderWindow_isOpen(w)) {
        z = fctevent(z, w);
        if (z.life == 3)
            sfRenderWindow_close(w);
        did(z); h = sfClock_getElapsedTime(k); t1 = sfClock_getElapsedTime(j);
        if ((t1.microseconds / 1000000.0) > 0.01) {
            sfClock_restart(j); z = editbird(z);
        } if ((h.microseconds / 1000000.0) > 0.15) {
            z = editarea(z); sfClock_restart(k);
        } cds(z, w, s);
    }
    return z.score;
}

void cds(struct bird newbird, sfRenderWindow *window, sfSprite *sprite)
{
    sfSprite_setTextureRect(newbird.sprite, newbird.area01);
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_drawSprite(window, newbird.sprite, NULL);
    sfRenderWindow_display(window);
}

void did(struct bird newbird)
{
    sfTexture *texture02 = sfTexture_createFromFile("o.png", NULL);
    sfSprite_setScale(newbird.sprite, newbird.scale_oiseau);
    sfSprite_setTexture(newbird.sprite, texture02, sfTrue);
    sfSprite_setPosition(newbird.sprite, newbird.pos_oiseau);
}
