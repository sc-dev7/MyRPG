/*
** EPITECH PROJECT, 2022
** hun
** File description:
** ter2
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

struct bird comparemouse(struct bird newbird, sfVector2i pos_mouse)
{
    int x = newbird.pos_oiseau.x;
    int y = newbird.pos_oiseau.y;
    if ( x < pos_mouse.x && (pos_mouse.x < (x+ 110))) {
        if ( y < pos_mouse.y && (pos_mouse.y < (y + 50))) {
        newbird.pos_oiseau.x = 0;
        newbird.pos_oiseau.y = num_alea();
        newbird.score = newbird.score + 1;
        }
    }
    return newbird;
}

int num_alea(void)
{
    srand (time (NULL));
    int nbgen = rand() % 900;
    return nbgen;
}

struct bird createbird(void)
{
    struct bird newbird;
    newbird.sprite = sfSprite_create();
    sfVector2f pos_oiso = {0, num_alea()};
    newbird.pos_oiseau = pos_oiso;
    sfVector2f scale_oiso = {0.8, 0.8};
    newbird.scale_oiseau = scale_oiso;
    sfIntRect area_oiso = {0, 0, 110, 110};
    newbird.area01 = area_oiso;
    newbird.life = 0;
    newbird.score = 0;
    newbird.speed = 15;
    return newbird;
}

struct bird editbird(struct bird newbird)
{
    if (newbird.score == 10) {
        newbird.speed = 20;
    } if (newbird.score == 20) {
        newbird.speed = 22;
    } if (newbird.score == 30) {
        newbird.speed = 25;
    } if (newbird.score == 40) {
        newbird.speed = 28;
    } if (newbird.score == 55) {
        newbird.speed = 30;
    } if (newbird.pos_oiseau.x > 1900) {
        newbird.life = newbird.life + 1; newbird.pos_oiseau.x = 0;
        newbird.pos_oiseau.y = num_alea();
    } else {
        newbird.pos_oiseau.x = newbird.pos_oiseau.x + newbird.speed;
    }
    return newbird;
}

struct bird editarea(struct bird newbird)
{
    if (newbird.area01.left == 220) {
        newbird.area01.left = 0;
    } else {
        newbird.area01.left = newbird.area01.left + 110;
    }
    return newbird;
}
