/*
** EPITECH PROJECT, 2022
** str
** File description:
** uct
*/

#ifndef _MACRO_
    #define _MACRO_

struct bird {
    sfSprite *sprite;
    int x;
    int y;
    sfVector2f pos_oiseau;
    sfVector2f scale_oiseau;
    sfIntRect area01;
    int life;
    int score;
    int speed;
};

#endif
