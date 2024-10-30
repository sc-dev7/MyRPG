u/*
** EPITECH PROJECT, 2022
** my_rpg.c
** File description:
** my_rpg
*/
#include "my.h"

static sfRenderWindow * create_renderwindow(unsigned int x, unsigned int y, unsigned int app, char *titre)
{
     sfVideoMode video_mode = {x, y, app};
     return (sfRenderWindow_create(video_mode, titre, sfResize | sfClose, NULL));
}

allim *addnode(struct node *new, allim *all)
{
    if (all->noda == NULL) {
        all->noda = new;
    } else {
        struct node *current = all->noda;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
    }
    return all;
}

void printlstch(allim *all)
{
    struct node *it = all->noda;
    while (it != NULL) {
        if (it->val != 10) {
            sfVector2f pos = {it->pos_x, it->pos_y};
            sfSprite_setScale(it->s, it->scale);
            sfSprite_setPosition(it->s, pos);
            sfSprite_setTexture(it->s, it->t, sfTrue);
            if (it->val == PLAYER) {
                sfSprite_setTextureRect(it->s, it->area);
            }
            sfRenderWindow_drawSprite(all->w, it->s, NULL);
        }
        it = it->next;
    }
}

allim *dosound(allim *all) 
{
    struct node *it = all->noda;
    while (it != NULL) {
        if (it->val == NOSOUND)
            it->val = 10;
        it = it->next;
    }
    return all;
}

allim *resume(allim *all) 
{
    struct node *it = all->noda;
    while (it != NULL) {
        if (it->val == GAMEMENU)
            it->val = 10;
        it = it->next;
    }
    return all;
}

allim *allarea(allim *all)
{
    sfIntRect area = {0, 0, 64, 64}; all->player_B0 = area;
    sfIntRect area01 = {64, 0, 64, 64}; all->player_B1 = area01;
    sfIntRect area02 = {128, 0, 64, 64}; all->player_B2 = area02;
    sfIntRect area03 = {192, 0, 64, 64}; all->player_B3 = area03;
    sfIntRect area04 = {0, 64, 64, 64}; all->player_L0 = area04;
    sfIntRect area05 = {64, 64, 64, 64}; all->player_L1 = area05;
    sfIntRect area06 = {128, 64, 64, 64}; all->player_L2 = area06;
    sfIntRect area07 = {192, 64, 64, 64}; all->player_L3 = area07;
    sfIntRect area08 = {0, 128, 64, 64}; all->player_R0 = area08;
    sfIntRect area09 = {64, 128, 64, 64}; all->player_R1 = area09;
    sfIntRect area10 = {128, 128, 64, 64}; all->player_R2 = area10;
    sfIntRect area11 = {192, 128, 64, 64}; all->player_R3 = area11;
    sfIntRect area12 = {0, 192, 64, 64}; all->player_T0 = area12;
    sfIntRect area13 = {64, 192, 64, 64}; all->player_T1 = area13;
    sfIntRect area14 = {128, 192, 64, 64}; all->player_T2 = area14;
    sfIntRect area15 = {192, 192, 64, 64}; all->player_T3 = area15;
    return all;
}

allim *editlstup(allim *all, int o)
{
    struct node *it = all->noda;
    while (it != NULL) {
        if (it->val == PLAYER) {
            it->pos_y = it->pos_y - o;
            all->pos_player.y = all->pos_player.y - o;
        }
        it = it->next;
    }
    return all;
}

allim *editlstdown(allim *all, int o)
{
    struct node *it = all->noda;
    while (it != NULL) {
        if (it->val == PLAYER) {
            it->pos_y = it->pos_y + o;
            all->pos_player.y = all->pos_player.y + o;
        }
        it = it->next;
    }
    return all;
}

allim *editlstright(allim *all, int o)
{
    struct node *it = all->noda;
    while (it != NULL) {
        if (it->val == PLAYER) {
            it->pos_x = it->pos_x + o;
            all->pos_player.x = all->pos_player.x + o;
        }
        it = it->next;
    }
    return all;
}

allim *editlstleft(allim *all, int o)
{
    struct node *it = all->noda;
    while (it != NULL) {
        if (it->val == PLAYER) {
            it->pos_x = it->pos_x - o;
            all->pos_player.x = all->pos_player.x - o;
        }
        it = it->next;
    }
    return all;
}

allim *editleftarea(allim *all)
{
    int p = 0;
    struct node *it = all->noda;
    while (it != NULL) {
        if (it->val == PLAYER) {
            if (it->areaint == AREAL0) {
                p++;
                it->areaint = AREAL1;
                it->area = all->player_L1;
            }
            if (it->areaint == AREAL1) {
                p++;
                it->areaint = AREAL2;
                it->area = all->player_L2;
            }
            if (it->areaint == AREAL2) {
                p++;
                it->areaint = AREAL3;
                it->area = all->player_L3;
            }
            if (p == 0) {
                it->area = all->player_L0;
                it->areaint = AREAL0;
            }
        }
        it = it->next;
    }
    return all;
}

allim *editrightarea(allim *all)
{
    int p = 0;
    struct node *it = all->noda;
    while (it != NULL) {
        if (it->val == PLAYER) {
            if (it->areaint == AREAR0) {
                p++;
                it->areaint = AREAR1;
                it->area = all->player_R1;
            }
            if (it->areaint == AREAR1) {
                p++;
                it->areaint = AREAR2;
                it->area = all->player_R2;
            }
            if (it->areaint == AREAR2) {
                p++;
                it->areaint = AREAR3;
                it->area = all->player_R3;
            }
            if (p == 0) {
                it->area = all->player_R0;
                it->areaint = AREAR0;
            }
        }
        it = it->next;
    }
    return all;
}

allim *edituparea(allim *all)
{
    int p = 0;
    struct node *it = all->noda;
    while (it != NULL) {
        if (it->val == PLAYER) {
            if (it->areaint == AREAT0) {
                p++;
                it->areaint = AREAT1;
                it->area = all->player_T1;
            }
            if (it->areaint == AREAT1) {
                p++;
                it->areaint = AREAT2;
                it->area = all->player_T2;
            }
            if (it->areaint == AREAT2) {
                p++;
                it->areaint = AREAT3;
                it->area = all->player_T3;
            }
            if (p == 0) {
                it->area = all->player_T0;
                it->areaint = AREAT0;
            }
        }
        it = it->next;
    }
    return all;
}

allim *editdownarea(allim *all)
{
    int p = 0;
    struct node *it = all->noda;
    while (it != NULL) {
        if (it->val == PLAYER) {
            if (it->areaint == AREAB0) {
                p++;
                it->areaint = AREAB1;
                it->area = all->player_B1;
            }
            if (it->areaint == AREAB1) {
                p++;
                it->areaint = AREAB2;
                it->area = all->player_B2;
            }
            if (it->areaint == AREAB2) {
                p++;
                it->areaint = AREAB3;
                it->area = all->player_B3;
            }
            if (p == 0) {
                it->area = all->player_B0;
                it->areaint = AREAB0;
            }
        }
        it = it->next;
    }
    return all;
}

allim *editareadial(allim *all)
{
    int p = 0;
    struct node *it = all->noda;
    while (it != NULL) {
        if (it->val == PLAYER) {
            it->area = all->player_L0;
            it->areaint = AREAL0;
        }
        it = it->next;
    }
    return all;
}

allim *enlevAprparler(allim *all)
{
    int p = 0;
    struct node *it = all->noda;
    while (it != NULL) {
        if (it->val == APRPARLER) {
            it->val = 10;
        }
        it = it->next;
    }
    return all;
}

allim *enlevAprjouer(allim *all)
{
    int p = 0;
    struct node *it = all->noda;
    while (it != NULL) {
        if (it->val == APRJOUER) {
            it->val = 10;
        }
        it = it->next;
    }
    return all;
}

allim *enlevAprparler2(allim *all)
{
    int p = 0;
    struct node *it = all->noda;
    while (it != NULL) {
        if (it->val == APRPARLER2) {
            it->val = 10;
        }
        it = it->next;
    }
    return all;
}

allim *editareadial2(allim *all)
{
    int p = 0;
    struct node *it = all->noda;
    while (it != NULL) {
        if (it->val == PLAYER) {
            it->area = all->player_B0;
            it->areaint = AREAB0;
        }
        it = it->next;
    }
    return all;
}

allim *editdial1(allim *all)
{
    struct node *it = all->noda;
    while (it != NULL) {
        if (it->val == DIALFEMME) {
            it->t = all->t13;
            it->s = all->s13;
        }
        it = it->next;
    }
    my_putchar('q');
    return all;
}

allim *editdial3(allim *all)
{
    struct node *it = all->noda;
    while (it != NULL) {
        if (it->val == DIALFEMME) {
            it->val = 10;
        }
        it = it->next;
    }
    my_putchar('q');
    return all;
}

int limitations(allim *all, int h, int b)
{
    if ((((all->pos_player.x + h) >= 40) && ((all->pos_player.x + h) <= 180)) && (((all->pos_player.y + b) >= 0) && ((all->pos_player.y + b) <= 80))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 0) && ((all->pos_player.x + h) <= 420)) && (((all->pos_player.y + b) >= 240) && ((all->pos_player.y + b) <= 360))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 320) && ((all->pos_player.x + h) <= 530)) && (((all->pos_player.y + b) >= 200) && ((all->pos_player.y + b) <= 250))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 390) && ((all->pos_player.x + h) <= 530)) && (((all->pos_player.y + b) >= 160) && ((all->pos_player.y + b) <= 190))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 540) && ((all->pos_player.x + h) <= 1750)) && (((all->pos_player.y + b) >= 60) && ((all->pos_player.y + b) <= 220))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 660) && ((all->pos_player.x + h) <= 1100)) && (((all->pos_player.y + b) >= 40) && ((all->pos_player.y + b) <= 50))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 1430) && ((all->pos_player.x + h) <= 1720)) && (((all->pos_player.y + b) >= 50) && ((all->pos_player.y + b) <= 60))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 1615) && ((all->pos_player.x + h) <= 1750)) && (((all->pos_player.y + b) >= 230) && ((all->pos_player.y + b) <= 380))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 1640) && ((all->pos_player.x + h) <= 1750)) && (((all->pos_player.y + b) >= 390) && ((all->pos_player.y + b) <= 440))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 1380) && ((all->pos_player.x + h) <= 1730)) && (((all->pos_player.y + b) >= 450) && ((all->pos_player.y + b) <= 540))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 1510) && ((all->pos_player.x + h) <= 1720)) && (((all->pos_player.y + b) >= 630) && ((all->pos_player.y + b) <= 820))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 1730) && ((all->pos_player.x + h) <= 1850)) && (((all->pos_player.y + b) >= 640) && ((all->pos_player.y + b) <= 820))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 1450) && ((all->pos_player.x + h) <= 1500)) && (((all->pos_player.y + b) >= 670) && ((all->pos_player.y + b) <= 770))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 1630) && ((all->pos_player.x + h) <= 1800)) && (((all->pos_player.y + b) >= 830) && ((all->pos_player.y + b) <= 870))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 1265) && ((all->pos_player.x + h) <= 1560)) && (((all->pos_player.y + b) >= 290) && ((all->pos_player.y + b) <= 350))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 1305) && ((all->pos_player.x + h) <= 1410)) && (((all->pos_player.y + b) >= 530) && ((all->pos_player.y + b) <= 600))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 1325) && ((all->pos_player.x + h) <= 1425)) && (((all->pos_player.y + b) >= 410) && ((all->pos_player.y + b) <= 440))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 1280) && ((all->pos_player.x + h) <= 1390)) && (((all->pos_player.y + b) >= 360) && ((all->pos_player.y + b) <= 400))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 1240) && ((all->pos_player.x + h) <= 1480)) && (((all->pos_player.y + b) >= 890) && ((all->pos_player.y + b) <= 950))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 1060) && ((all->pos_player.x + h) <= 1130)) && (((all->pos_player.y + b) >= 940) && ((all->pos_player.y + b) <= 950))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 950) && ((all->pos_player.x + h) <= 1050)) && (((all->pos_player.y + b) >= 910) && ((all->pos_player.y + b) <= 950))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 0) && ((all->pos_player.x + h) <= 810)) && (((all->pos_player.y + b) >= 750) && ((all->pos_player.y + b) <= 950))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 820) && ((all->pos_player.x + h) <= 870)) && (((all->pos_player.y + b) >= 870) && ((all->pos_player.y + b) <= 950))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 880) && ((all->pos_player.x + h) <= 950)) && (((all->pos_player.y + b) >= 900) && ((all->pos_player.y + b) <= 950))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 820) && ((all->pos_player.x + h) <= 1010)) && (((all->pos_player.y + b) >= 680) && ((all->pos_player.y + b) <= 840))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 1020) && ((all->pos_player.x + h) <= 1290)) && (((all->pos_player.y + b) >= 690) && ((all->pos_player.y + b) <= 770))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 1020) && ((all->pos_player.x + h) <= 1110)) && (((all->pos_player.y + b) >= 780) && ((all->pos_player.y + b) <= 820))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 820) && ((all->pos_player.x + h) <= 970)) && (((all->pos_player.y + b) >= 570) && ((all->pos_player.y + b) <= 670))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 760) && ((all->pos_player.x + h) <= 810)) && (((all->pos_player.y + b) >= 640) && ((all->pos_player.y + b) <= 740))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 840) && ((all->pos_player.x + h) <= 1050)) && (((all->pos_player.y + b) >= 510) && ((all->pos_player.y + b) <= 560))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 970) && ((all->pos_player.x + h) <= 1010)) && (((all->pos_player.y + b) >= 680) && ((all->pos_player.y + b) <= 840))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 530) && ((all->pos_player.x + h) <= 750)) && (((all->pos_player.y + b) >= 700) && ((all->pos_player.y + b) <= 740))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 780) && ((all->pos_player.x + h) <= 810)) && (((all->pos_player.y + b) >= 580) && ((all->pos_player.y + b) <= 630))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 0) && ((all->pos_player.x + h) <= 340)) && (((all->pos_player.y + b) >= 710) && ((all->pos_player.y + b) <= 740))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 0) && ((all->pos_player.x + h) <= 220)) && (((all->pos_player.y + b) >= 680) && ((all->pos_player.y + b) <= 700))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 0) && ((all->pos_player.x + h) <= 150)) && (((all->pos_player.y + b) >= 500) && ((all->pos_player.y + b) <= 560))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 60) && ((all->pos_player.x + h) <= 150)) && (((all->pos_player.y + b) >= 570) && ((all->pos_player.y + b) <= 600))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 970) && ((all->pos_player.x + h) <= 1100)) && (((all->pos_player.y + b) >= 470) && ((all->pos_player.y + b) <= 500))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 1060) && ((all->pos_player.x + h) <= 1090)) && (((all->pos_player.y + b) >= 510) && ((all->pos_player.y + b) <= 540))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 1000) && ((all->pos_player.x + h) <= 1140)) && (((all->pos_player.y + b) >= 440) && ((all->pos_player.y + b) <= 470))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 1040) && ((all->pos_player.x + h) <= 1080)) && (((all->pos_player.y + b) >= 410) && ((all->pos_player.y + b) <= 430))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 430) && ((all->pos_player.x + h) <= 660)) && (((all->pos_player.y + b) >= 260) && ((all->pos_player.y + b) <= 330))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 660) && ((all->pos_player.x + h) <= 790)) && (((all->pos_player.y + b) >= 230) && ((all->pos_player.y + b) <= 260))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 840) && ((all->pos_player.x + h) <= 930)) && (((all->pos_player.y + b) >= 230) && ((all->pos_player.y + b) <= 270))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 1460) && ((all->pos_player.x + h) <= 1520)) && (((all->pos_player.y + b) >= 250) && ((all->pos_player.y + b) <= 280))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 1070) && ((all->pos_player.x + h) <= 1190)) && (((all->pos_player.y + b) >= 230) && ((all->pos_player.y + b) <= 280))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 510) && ((all->pos_player.x + h) <= 660)) && (((all->pos_player.y + b) >= 340) && ((all->pos_player.y + b) <= 630))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 460) && ((all->pos_player.x + h) <= 500)) && (((all->pos_player.y + b) >= 560) && ((all->pos_player.y + b) <= 630))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 410) && ((all->pos_player.x + h) <= 500)) && (((all->pos_player.y + b) >= 420) && ((all->pos_player.y + b) <= 500))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 440) && ((all->pos_player.x + h) <= 500)) && (((all->pos_player.y + b) >= 510) && ((all->pos_player.y + b) <= 550))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 0) && ((all->pos_player.x + h) <= 210)) && (((all->pos_player.y + b) >= 370) && ((all->pos_player.y + b) <= 400))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 0) && ((all->pos_player.x + h) <= 180)) && (((all->pos_player.y + b) >= 410) && ((all->pos_player.y + b) <= 420))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 0) && ((all->pos_player.x + h) <= 140)) && (((all->pos_player.y + b) >= 430) && ((all->pos_player.y + b) <= 440))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 0) && ((all->pos_player.x + h) <= 120)) && (((all->pos_player.y + b) >= 450) && ((all->pos_player.y + b) <= 490))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 670) && ((all->pos_player.x + h) <= 790)) && (((all->pos_player.y + b) >= 340) && ((all->pos_player.y + b) <= 490))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 1465) && ((all->pos_player.x + h) <= 1565)) && (((all->pos_player.y + b) >= 360) && ((all->pos_player.y + b) <= 390))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 800) && ((all->pos_player.x + h) <= 1000)) && (((all->pos_player.y + b) >= 360) && ((all->pos_player.y + b) <= 400))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 810) && ((all->pos_player.x + h) <= 970)) && (((all->pos_player.y + b) >= 410) && ((all->pos_player.y + b) <= 440))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 850) && ((all->pos_player.x + h) <= 950)) && (((all->pos_player.y + b) >= 450) && ((all->pos_player.y + b) <= 460))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 880) && ((all->pos_player.x + h) <= 940)) && (((all->pos_player.y + b) >= 470) && ((all->pos_player.y + b) <= 480))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 430) && ((all->pos_player.x + h) <= 440)) && (((all->pos_player.y + b) >= 340) && ((all->pos_player.y + b) <= 360))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 130) && ((all->pos_player.x + h) <= 310)) && (((all->pos_player.y + b) >= 480) && ((all->pos_player.y + b) <= 490))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 310) && ((all->pos_player.x + h) <= 320)) && (((all->pos_player.y + b) >= 500) && ((all->pos_player.y + b) <= 650))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 1190) && ((all->pos_player.x + h) <= 1280)) && (((all->pos_player.y + b) >= 530) && ((all->pos_player.y + b) <= 580))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 1160) && ((all->pos_player.x + h) <= 1180)) && (((all->pos_player.y + b) >= 575) && ((all->pos_player.y + b) <= 585))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 200) && ((all->pos_player.x + h) <= 320)) && (((all->pos_player.y + b) >= -10) && ((all->pos_player.y + b) <= 30))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 430) && ((all->pos_player.x + h) <= 440)) && (((all->pos_player.y + b) >= 340) && ((all->pos_player.y + b) <= 360))) {
        return 1;
    }
    if ((((all->pos_player.x + h) >= 430) && ((all->pos_player.x + h) <= 440)) && (((all->pos_player.y + b) >= 340) && ((all->pos_player.y + b) <= 360))) {
        return 1;
    }
    if (all->pos_player.y + b < -20)
        return 1;
    if (all->pos_player.y + b > 950)
        return 1;
    if (all->pos_player.x + h > 1850)
        return 1;
    if (all->pos_player.x + h < 0)
        return 1;
    return 0;
}

char *my_strcat(char *str1, char *str2)
{
    char *str3 = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));
    int i = 0;
    while (i != my_strlen(str1)) {
        str3[i] = str1[i];
        i++;
    }
    int b = 0;
    while (b != my_strlen(str2)) {
        str3[i] = str2[b];
        i++; b++;
    }
    str3[i] = '\0';
    return str3;
}

char *itoa(int nb)
{
    int a = nb;
    int val = 0;
    if (a == 0)
        val = 1;
    while (a > 0) {
        a = a / 10;
        val++;
    }
    char *str = malloc(sizeof(char) * (val));
    int i = 0;
    for (; i != val; i++) {
        str[i] = nb % 10 + 48;
        nb = nb / 10;
    }
    str[i] = '\0';
    my_revstr(str);
    return str;
}

char *mon_buf(char *str)
{
    struct stat tmap;
    stat(str, &tmap);
    int nb = tmap.st_size;
    int fd = open(str,O_RDONLY);
    char *buf = malloc(sizeof(char) * nb);
    int rd = read(fd,buf,nb);
    close(rd);
    return buf;
}

int len(char *str, int i) 
{
    int j = 1;
    while(str[i] != '\n') {
        j++;
        i++;
    }
    return (j);
}

allim *editposPx(allim *all, int x)
{
    struct node *it = all->noda;
    while (it != NULL) {
        if (it->val == PLAYER) {
            it->pos_x = x;
        }
        it = it->next;
    }
    return all;
}

allim *editposPy(allim *all, int y)
{
    struct node *it = all->noda;
    while (it != NULL) {
        if (it->val == PLAYER) {
            it->pos_y = y;
        }
        it = it->next;
    }
    return all;
}

allim *editview(allim *all)
{
    struct node *it = all->noda;
    while (it != NULL) {
        if (it->val == GAMEMENU) {
            it->val = 10;
        }
        it = it->next;
    }
    return all;
}

allim *return_valeur(char *string, int m, allim *all)
{
    my_putstr("h\nh\n");
    (m == 0) ? all->xview = my_getnbr(string): 0;
    (m == 1) ? all->yview = my_getnbr(string): 0;
    (m == 2) ? all->scorehunter = my_getnbr(string): 0;
    (m == 3) ? all->duréedial = my_getnbr(string): 0;
    (m == 4) ? all->action = my_getnbr(string): 0;
    (m == 5) ? all->pos_player.x = my_getnbr(string): 0;
    (m == 5) ? editposPx(all, my_getnbr(string)) : 0;
    (m == 6) ? all->pos_player.y = my_getnbr(string): 0;
    (m == 6) ? editposPy(all, my_getnbr(string)) : 0;
    (m == 7) ? all->pos_sound.x = my_getnbr(string): 0;
    (m == 8) ? all->pos_sound.y = my_getnbr(string): 0;
    (m == 9) ? all->page = my_getnbr(string): 0;
    return all;
}


int main(void)
{
    int c = 0;
    allim *all = malloc(sizeof(allim));
    all->w = create_renderwindow(1920, 1080, 32, "Allez l'OM");
    sfEvent event;
    int r = 0;
    all->t01 = sfTexture_createFromFile("fond_menu", NULL);
    all->t02 = sfTexture_createFromFile("croixrouge", NULL);
    all->t03 = sfTexture_createFromFile("map", NULL);
    all->t04 = sfTexture_createFromFile("playerrpg", NULL);
    all->t05 = sfTexture_createFromFile("house1.png", NULL);
    all->t06 = sfTexture_createFromFile("gamemenu", NULL);
    all->t07 = sfTexture_createFromFile("house2.jpg", NULL);
    all->t08 = sfTexture_createFromFile("house3.png", NULL);
    all->t09 = sfTexture_createFromFile("house4.png", NULL);
    all->t10 = sfTexture_createFromFile("house5.png", NULL);
    all->t11 = sfTexture_createFromFile("house6black.png", NULL);
    all->t12 = sfTexture_createFromFile("dialogue1", NULL);
    all->t13 = sfTexture_createFromFile("dialogue2", NULL);
    all->t14 = sfTexture_createFromFile("dialogue3", NULL);
    all->t15 = sfTexture_createFromFile("dialogue4", NULL);
    all->t16 = sfTexture_createFromFile("dialogue5", NULL);
    all->t17 = sfTexture_createFromFile("gamemenu1cup", NULL);
    all->t18 = sfTexture_createFromFile("dialogue6", NULL);
    all->t19 = sfTexture_createFromFile("dialogue7", NULL);
    all->t20 = sfTexture_createFromFile("dialogue8", NULL);
    all->t21 = sfTexture_createFromFile("Aprparler", NULL);
    all->t22 = sfTexture_createFromFile("Aprparler", NULL);
    all->t23 = sfTexture_createFromFile("Aprjouer", NULL);
    all->s01 = sfSprite_create();
    all->s02 = sfSprite_create();
    all->s03 = sfSprite_create();
    all->s04 = sfSprite_create();
    all->s05 = sfSprite_create();
    all->s06 = sfSprite_create();
    all->s07 = sfSprite_create();
    all->s08 = sfSprite_create();
    all->s09 = sfSprite_create();
    all->s10 = sfSprite_create();
    all->s11 = sfSprite_create();
    all->s12 = sfSprite_create();
    all->s13 = sfSprite_create();
    all->s14 = sfSprite_create();
    all->s15 = sfSprite_create();
    all->s16 = sfSprite_create();
    all->s17 = sfSprite_create();
    all->s18 = sfSprite_create();
    all->s19 = sfSprite_create();
    all->s20 = sfSprite_create();
    all->s21 = sfSprite_create();
    all->s22 = sfSprite_create();
    all->s23 = sfSprite_create();
    all->scale01.x = 1.52;
    all->scale01.y = 1.44;
    all->scale02.x = 0.3;
    all->scale02.y = 0.3;
    all->scale03.x = 1;
    all->scale03.y = 0.715;
    all->scale04.x = 1;
    all->scale04.y = 1;
    all->scale05.x = 2.3;
    all->scale05.y = 2.5;
    all->scale06.x = 0.8;
    all->scorehunter = 0;
    all->ifgamemenu = 0;
    all->scale06.y = 0.8;
    all->scale07.x = 2.3;
    all->scale07.y = 2.5;
    all->scale08.x = 6.4;
    all->scale08.y = 7.7;
    all->scale09.x = 5.2;
    all->action = RIEN;
    all->scale09.y = 6.0;
    all->scale10.x = 7.0;
    all->duréedial = 0;
    all->scale10.y = 7.5;
    all->scale11.x = 2.0;
    all->scale11.y = 2.4;
    all->scale12.x = 2.0;
    all->scale12.y = 2.4;
    all->scale13.x = 2;
    all->scale13.y = 2;
    all->scale14.x = 2;
    all->scale14.y = 2;
    all->pos_player.x = 810;
    all->pos_player.y = 310;
    all->pos_Aprparler.x = 810;
    all->pos_Aprparler.y = 310;
    all->pos_Aprjouer.x = 810;
    all->pos_Aprjouer.y = 310;
    all->pos_dialfemme.x = 700;
    all->pos_dialfemme.y = 200;
    int z = 0;
    sfVector2i pos_mou;
    all->pos_sound.x = 50;
    all->pos_sound.y = 920;
    struct node *new = malloc(sizeof(struct node));
    new->s = all->s01;
    new->t = all->t01;
    int i = 0;
    // new->pos_x = 40;
    // new->pos_y = 50;
    new->scale = all->scale01;
    new->val = MENU;
    new->next = NULL;
    sfClock *k = sfClock_create();
    sfClock *d = sfClock_create();
    sfTime t1;
    sfTime t2;
    all = allarea(all);
    all = addnode(new, all);
    sfMusic* music = sfMusic_createFromFile("om.ogg");
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    sfView* view = sfView_create();
    all->xview = 900;
    all->yview = 400;
    int a = 0;
    int b = 0;
    sfView_setCenter(view, (sfVector2f){all->xview, all->yview});
    sfView_setSize(view, (sfVector2f){1000, 500});
    all->sound = SOUND; all->page = MENU;
    while (sfRenderWindow_isOpen(all->w)) {
        while (sfRenderWindow_pollEvent(all->w, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(all->w);
            if (event.type == sfEvtMouseButtonPressed) {
                r = 0;
                pos_mou = sfMouse_getPositionRenderWindow(all->w);
                my_put_nbr(pos_mou.x);
                my_putchar('-');
                my_put_nbr(pos_mou.y);
                my_putchar('\n');
                if ((pos_mou.x > 53 && pos_mou.x < 132) && (pos_mou.y > 915 && pos_mou.y < 1018) && all->page == MENU) {
                    if (all->sound == SOUND) {
                        struct node *new = malloc(sizeof(struct node));
                        new->s = all->s02;
                        new->t = all->t02;
                        new->pos_x = all->pos_sound.x;
                        new->pos_y = all->pos_sound.y;
                        new->scale = all->scale02;
                        new->val = NOSOUND;
                        new->next = NULL;
                        all = addnode(new, all);
                        sfMusic_pause(music);
                        all->sound = NOSOUND;
                    } else {
                        all = dosound(all);
                        sfMusic_setLoop(music, sfTrue);
                        sfMusic_play(music);
                        all->sound = SOUND;
                    }
                }
                if ((pos_mou.x > 822 && pos_mou.x < 1128) && (pos_mou.y > 802 && pos_mou.y < 907) && all->page == MENU)
                    sfRenderWindow_close(all->w);
                if ((pos_mou.x > 679 && pos_mou.x < 1265) && (pos_mou.y > 239 && pos_mou.y < 475) && all->page == MENU) {
                    all->noda = NULL;
                    all->page = GAME1;
                    struct node *ne = malloc(sizeof(struct node));
                    ne->s = all->s03;
                    ne->t = all->t03;
                    ne->pos_x = 0;
                    ne->pos_y = 0;
                    ne->scale = all->scale03;
                    ne->val = NOSOUND;
                    ne->next = NULL;
                    all = addnode(ne, all);
                    sfRenderWindow_setView(all->w, view);
                }

                if ((pos_mou.x > 1190 && pos_mou.x < 1574) && (pos_mou.y > 243 && pos_mou.y < 352) && all->ifgamemenu == 1) {
                    my_putstr("\n\n");
                    all = resume(all);
                    all->ifgamemenu = 0;
                }
            }
        }
        if (all->ifgamemenu == 1 && r == 0) {
            if (pos_mou.x >= 379 && pos_mou.x <= 562 && pos_mou.y >= 849 && pos_mou.y <= 909) {
                my_putstr("dsqfgdfqsg");
                char *str1 = itoa(all->xview);
                char *str2 = itoa(all->yview);
                char *str3 = itoa(all->scorehunter);
                char *str4 = itoa(all->duréedial);
                char *str5 = itoa(all->action);
                char *str6 = itoa(all->pos_player.x);
                char *str7 = itoa(all->pos_player.y);
                char *str8 = itoa(all->pos_sound.x);
                char *str9 = itoa(all->pos_sound.y);
                char *str10 = itoa(all->page);
                str1 = my_strcat(str1, "\n");
                str2 = my_strcat(str2, "\n");
                str3 = my_strcat(str3, "\n");
                str4 = my_strcat(str4, "\n");
                str5 = my_strcat(str5, "\n");
                str6 = my_strcat(str6, "\n");
                str7 = my_strcat(str7, "\n");
                str8 = my_strcat(str8, "\n");
                str9 = my_strcat(str9, "\n");
                str10 = my_strcat(str10, "\n");
                int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
                write(fd,str1,my_strlen(str1));
                write(fd,str2,my_strlen(str2));
                write(fd,str3,my_strlen(str3));
                write(fd,str4,my_strlen(str4));
                write(fd,str5,my_strlen(str5));
                write(fd,str6,my_strlen(str6));
                write(fd,str7,my_strlen(str7));
                write(fd,str8,my_strlen(str8));
                write(fd,str9,my_strlen(str9));
                write(fd,str10,my_strlen(str10));
                close(fd);
                r++;
            }
        }
        if (all->ifgamemenu == 1) {
            if (pos_mou.x >= 610 && pos_mou.x <= 809 && pos_mou.y >= 841 && pos_mou.y <= 914) {
                if (r == 0) {
                    char *str = mon_buf("test.txt");
                    int i = 0;
                    int m = 0;
                    while(m != 10) {
                        char *string = malloc(sizeof(char) * len(str,i));
                        int l = 0;
                        while (str[i] != '\n') {
                            string[l] = str[i];
                            i++; l++;
                        }
                        string[l] = '\0';
                        all = return_valeur(string, m, all);
                        m++;
                        i++;
                    }
                }
                editview(all);
                struct node *ne = malloc(sizeof(struct node));
                if (all->scorehunter >= 7) {
                    ne->s = all->s17;
                    ne->t = all->t17;
                } else {
                    ne->s = all->s06;
                    ne->t = all->t06;
                }
                ne->pos_x = all->xview - 330;
                ne->pos_y = all->yview - 260;
                ne->scale.x = 0.8;
                ne->scale.y = 0.8;
                ne->val = GAMEMENU;
                ne->next = NULL;
                all = addnode(ne, all);
                sfView_setCenter(view, (sfVector2f){all->xview, all->yview});
                sfView_setSize(view, (sfVector2f){1000, 500});
                printlstch(all);
                sfRenderWindow_setView(all->w, view);
                r = 1;
            }
        }

        t1 = sfClock_getElapsedTime(k);
        if ((all->pos_player.x >= 825 && all->pos_player.x <= 925) && (all->pos_player.y >= 550 && all->pos_player.y <= 625) && all->page == GAME4) {
            struct node *ne = malloc(sizeof(struct node));
            ne->s = all->s23;
            ne->t = all->t23;
            ne->pos_x = all->pos_Aprjouer.x;
            ne->pos_y = all->pos_Aprjouer.y;
            ne->scale = all->scale13;
            ne->val = APRJOUER;
            ne->next = NULL;
            all = addnode(ne, all);
            if (sfKeyboard_isKeyPressed(sfKeyA)) {
                if (all->scorehunter < 7) {
                    all->scorehunter = wind();
                } else {
                    wind();
                }
            }
        } else {
            enlevAprjouer(all);
        }
        if ((all->pos_player.x >= 1025 && all->pos_player.x <= 1125) && (all->pos_player.y >= 575 && all->pos_player.y <= 625) && all->page == GAME4) {
            // my_putstr("llelelele");
            if (all->duréedial == 0 || all->duréedial == 3 || all->duréedial == 9) {
                struct node *ne = malloc(sizeof(struct node));
                ne->s = all->s21;
                ne->t = all->t21;
                ne->pos_x = all->pos_Aprparler.x;
                ne->pos_y = all->pos_Aprparler.y;
                ne->scale = all->scale13;
                ne->val = APRPARLER;
                ne->next = NULL;
                all = addnode(ne, all);
            }
            sfRenderWindow_setView(all->w, view);
            if (sfKeyboard_isKeyPressed(sfKeyA) && all->duréedial == 0) {
                enlevAprparler(all);
                editareadial2(all);
                struct node *ne = malloc(sizeof(struct node));
                all->action = DIALFEMME;
                ne->s = all->s12;
                ne->t = all->t12;
                ne->pos_x = all->pos_dialfemme.x;
                ne->pos_y = all->pos_dialfemme.y;
                ne->scale = all->scale12;
                ne->val = DIALFEMME;
                ne->next = NULL;
                all = addnode(ne, all);
                printlstch(all);
                all->duréedial = 1;
                usleep(300000);
            }
            if (sfKeyboard_isKeyPressed(sfKeyA) && all->duréedial == 1) {
                all->action = DIALFEMME;
                all = editdial1(all);
                all->duréedial = 2;
                printlstch(all);
                usleep(300000);
            }
            if (sfKeyboard_isKeyPressed(sfKeyA) && all->duréedial == 2) {
                all = editdial3(all);
                all->action = RIEN;
                all->duréedial = 3;
                printlstch(all);
                usleep(300000);
            }
            if (sfKeyboard_isKeyPressed(sfKeyA) && all->duréedial == 3 && all->scorehunter < 7) {
                enlevAprparler(all);
                all->action = DIALFEMME;
                editareadial2(all);
                struct node *ne = malloc(sizeof(struct node));
                ne->s = all->s14;
                ne->t = all->t14;
                ne->pos_x = all->pos_dialfemme.x;
                ne->pos_y = all->pos_dialfemme.y;
                ne->scale = all->scale12;
                ne->val = DIALFEMME;
                ne->next = NULL;
                all = addnode(ne, all);
                printlstch(all);
                usleep(300000);
                all->duréedial = 4;
            }
            if (sfKeyboard_isKeyPressed(sfKeyA) && all->duréedial == 4 && all->scorehunter < 7) {
                all = editdial3(all);
                all->action = RIEN;
                all->duréedial = 3;
                usleep(300000);
            }
            if (sfKeyboard_isKeyPressed(sfKeyA) && all->duréedial == 3 && all->scorehunter >= 7) {
                enlevAprparler(all);
                struct node *ne = malloc(sizeof(struct node));
                editareadial2(all);
                ne->s = all->s15;
                ne->t = all->t15;
                ne->pos_x = all->pos_dialfemme.x;
                ne->pos_y = all->pos_dialfemme.y;
                ne->scale = all->scale12;
                ne->val = DIALFEMME;
                ne->next = NULL;
                all = addnode(ne, all);
                printlstch(all);
                all->action = DIALFEMME;
                usleep(300000);
                all->duréedial = 5;
            }
            if (sfKeyboard_isKeyPressed(sfKeyA) && all->duréedial == 5) {
                all = editdial3(all);
                struct node *ne = malloc(sizeof(struct node));
                ne->s = all->s16;
                ne->t = all->t16;
                ne->pos_x = all->pos_dialfemme.x;
                ne->pos_y = all->pos_dialfemme.y;
                ne->scale = all->scale12;
                ne->val = DIALFEMME;
                ne->next = NULL;
                all = addnode(ne, all);
                printlstch(all);
                all->action = DIALFEMME;
                usleep(300000);
                all->duréedial = 6;
            }
            if (sfKeyboard_isKeyPressed(sfKeyA) && all->duréedial == 6) {
                all = editdial3(all);
                struct node *ne = malloc(sizeof(struct node));
                ne->s = all->s18;
                ne->t = all->t18;
                ne->pos_x = all->pos_dialfemme.x;
                ne->pos_y = all->pos_dialfemme.y;
                ne->scale = all->scale12;
                ne->val = DIALFEMME;
                ne->next = NULL;
                all = addnode(ne, all);
                printlstch(all);
                all->action = DIALFEMME;
                usleep(300000);
                all->duréedial = 7;
            }
            if (sfKeyboard_isKeyPressed(sfKeyA) && all->duréedial == 7) {
                all = editdial3(all);
                struct node *ne = malloc(sizeof(struct node));
                ne->s = all->s19;
                ne->t = all->t19;
                ne->pos_x = all->pos_dialfemme.x;
                ne->pos_y = all->pos_dialfemme.y;
                ne->scale = all->scale12;
                ne->val = DIALFEMME;
                ne->next = NULL;
                all = addnode(ne, all);
                printlstch(all);
                all->action = DIALFEMME;
                usleep(300000);
                all->duréedial = 8;
            }
            if (sfKeyboard_isKeyPressed(sfKeyA) && all->duréedial == 8) {
                all = editdial3(all);
                usleep(300000);
                all->action = RIEN;
                all->duréedial = 9;
            }
            if (sfKeyboard_isKeyPressed(sfKeyA) && all->duréedial == 9) {
                enlevAprparler(all);
                editareadial2(all);
                struct node *ne = malloc(sizeof(struct node));
                ne->s = all->s20;
                ne->t = all->t20;
                ne->pos_x = all->pos_dialfemme.x;
                ne->pos_y = all->pos_dialfemme.y;
                ne->scale = all->scale12;
                ne->val = DIALFEMME;
                ne->next = NULL;
                all = addnode(ne, all);
                printlstch(all);
                all->action = DIALFEMME;
                all->duréedial = 10;
                usleep(300000);
            }
            if (sfKeyboard_isKeyPressed(sfKeyA) && all->duréedial == 10) {
                all = editdial3(all);
                usleep(300000);
                all->action = RIEN;
                all->duréedial = 9;
            }
        } else {
            all = enlevAprparler(all);
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape) && all->page != GAME1 && all->page != MENU && all->ifgamemenu == 0 && all->scorehunter >= 7) {
            struct node *ne = malloc(sizeof(struct node));
            usleep(200000);
            my_putstr("\n\n");
            ne->s = all->s17;
            ne->t = all->t17;
            ne->pos_x = -150;
            ne->pos_y = -120;
            ne->scale.x = 2.2;
            ne->scale.y = 2.2;
            ne->val = GAMEMENU;
            ne->next = NULL;
            all = addnode(ne, all);
            all->ifgamemenu = 1;
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape) && all->page == GAME1 && all->scorehunter >= 7) {
            struct node *ne = malloc(sizeof(struct node));
            usleep(200000);
            my_putstr("\n\n");
            ne->s = all->s17;
            ne->t = all->t17;
            ne->pos_x = all->xview - 330;
            ne->pos_y = all->yview - 260;
            ne->scale.x = 0.8;
            ne->scale.y = 0.8;
            ne->val = GAMEMENU;
            ne->next = NULL;
            all = addnode(ne, all);
            all->ifgamemenu = 1;
        }
        if ((all->pos_player.x >= 1125 && all->pos_player.x <= 1175) && (all->pos_player.y >= 700 && all->pos_player.y <= 775) && all->page == GAME4) {
            my_put_nbr(all->duréedial);my_putchar('\n');
            if (all->duréedial == 0 || all->duréedial == 3 || all->duréedial == 9) {
                struct node *ne = malloc(sizeof(struct node));
                ne->s = all->s21;
                ne->t = all->t21;
                ne->pos_x = all->pos_Aprparler.x;
                ne->pos_y = all->pos_Aprparler.y;
                ne->scale = all->scale13;
                ne->val = APRPARLER2;
                ne->next = NULL;
                all = addnode(ne, all);
            }
            if (sfKeyboard_isKeyPressed(sfKeyA) && all->duréedial == 0) {
                all = enlevAprparler2(all);
                editareadial(all);
                struct node *ne = malloc(sizeof(struct node));
                all->action = DIALFEMME;
                ne->s = all->s12;
                ne->t = all->t12;
                ne->pos_x = all->pos_dialfemme.x;
                ne->pos_y = all->pos_dialfemme.y;
                ne->scale = all->scale12;
                ne->val = DIALFEMME;
                ne->next = NULL;
                all = addnode(ne, all);
                printlstch(all);
                all->duréedial = 1;
                usleep(300000);
            }
            if (sfKeyboard_isKeyPressed(sfKeyA) && all->duréedial == 1) {
                all->action = DIALFEMME;
                all = editdial1(all);
                all->duréedial = 2;
                printlstch(all);
                usleep(300000);
            }
            if (sfKeyboard_isKeyPressed(sfKeyA) && all->duréedial == 2) {
                
                all = editdial3(all);
                all->action = RIEN;
                all->duréedial = 3;
                printlstch(all);
                usleep(300000);
            }
            if (sfKeyboard_isKeyPressed(sfKeyA) && all->duréedial == 3 && all->scorehunter < 7) {
                all = enlevAprparler2(all);
                all->action = DIALFEMME;
                editareadial(all);
                struct node *ne = malloc(sizeof(struct node));
                ne->s = all->s14;
                ne->t = all->t14;
                ne->pos_x = all->pos_dialfemme.x;
                ne->pos_y = all->pos_dialfemme.y;
                ne->scale = all->scale12;
                ne->val = DIALFEMME;
                ne->next = NULL;
                all = addnode(ne, all);
                printlstch(all);
                usleep(300000);
                all->duréedial = 4;
            }
            if (sfKeyboard_isKeyPressed(sfKeyA) && all->duréedial == 4 && all->scorehunter < 7) {
                all = editdial3(all);
                all->action = RIEN;
                all->duréedial = 3;
                usleep(300000);
            }
            if (sfKeyboard_isKeyPressed(sfKeyA) && all->duréedial == 3 && all->scorehunter >= 7) {
                all = enlevAprparler2(all);
                struct node *ne = malloc(sizeof(struct node));
                editareadial(all);
                ne->s = all->s15;
                ne->t = all->t15;
                ne->pos_x = all->pos_dialfemme.x;
                ne->pos_y = all->pos_dialfemme.y;
                ne->scale = all->scale12;
                ne->val = DIALFEMME;
                ne->next = NULL;
                all = addnode(ne, all);
                printlstch(all);
                all->action = DIALFEMME;
                usleep(300000);
                all->duréedial = 5;
            }
            if (sfKeyboard_isKeyPressed(sfKeyA) && all->duréedial == 5) {
                all = editdial3(all);
                struct node *ne = malloc(sizeof(struct node));
                ne->s = all->s16;
                ne->t = all->t16;
                ne->pos_x = all->pos_dialfemme.x;
                ne->pos_y = all->pos_dialfemme.y;
                ne->scale = all->scale12;
                ne->val = DIALFEMME;
                ne->next = NULL;
                all = addnode(ne, all);
                printlstch(all);
                all->action = DIALFEMME;
                usleep(300000);
                all->duréedial = 6;
            }
            if (sfKeyboard_isKeyPressed(sfKeyA) && all->duréedial == 6) {
                all = editdial3(all);
                struct node *ne = malloc(sizeof(struct node));
                ne->s = all->s18;
                ne->t = all->t18;
                ne->pos_x = all->pos_dialfemme.x;
                ne->pos_y = all->pos_dialfemme.y;
                ne->scale = all->scale12;
                ne->val = DIALFEMME;
                ne->next = NULL;
                all = addnode(ne, all);
                printlstch(all);
                all->action = DIALFEMME;
                usleep(300000);
                all->duréedial = 7;
            }
            if (sfKeyboard_isKeyPressed(sfKeyA) && all->duréedial == 7) {
                all = editdial3(all);
                struct node *ne = malloc(sizeof(struct node));
                ne->s = all->s19;
                ne->t = all->t19;
                ne->pos_x = all->pos_dialfemme.x;
                ne->pos_y = all->pos_dialfemme.y;
                ne->scale = all->scale12;
                ne->val = DIALFEMME;
                ne->next = NULL;
                all = addnode(ne, all);
                printlstch(all);
                all->action = DIALFEMME;
                usleep(300000);
                all->duréedial = 8;
            }
            if (sfKeyboard_isKeyPressed(sfKeyA) && all->duréedial == 8) {
                all = editdial3(all);
                usleep(300000);
                all->action = RIEN;
                all->duréedial = 9;
            }
            if (sfKeyboard_isKeyPressed(sfKeyA) && all->duréedial == 9) {
                all = enlevAprparler2(all);
                editareadial(all);
                struct node *ne = malloc(sizeof(struct node));
                ne->s = all->s20;
                ne->t = all->t20;
                ne->pos_x = all->pos_dialfemme.x;
                ne->pos_y = all->pos_dialfemme.y;
                ne->scale = all->scale12;
                ne->val = DIALFEMME;
                ne->next = NULL;
                all = addnode(ne, all);
                printlstch(all);
                all->action = DIALFEMME;
                all->duréedial = 10;
                usleep(300000);
            }
            if (sfKeyboard_isKeyPressed(sfKeyA) && all->duréedial == 10) {
                all = editdial3(all);
                usleep(300000);
                all->action = RIEN;
                all->duréedial = 9;
            }
        } else {
            all = enlevAprparler2(all);
        }
        if (sfKeyboard_isKeyPressed(sfKeyDown)) {
            if ((all->pos_player.x >= 150 && all->pos_player.x <= 275) && all->pos_player.y == 1100 && all->page == GAME3) {
                all->page = GAME1;
                all->noda = NULL;
                struct node *ne = malloc(sizeof(struct node));
                ne->s = all->s03;
                ne->t = all->t03;
                ne->pos_x = 0;
                ne->pos_y = 0;
                ne->scale = all->scale03;
                ne->val = GAME1;
                ne->next = NULL;
                all = addnode(ne, all);
                all->scale04.x = 1;
                all->scale04.y = 1;
                all->pos_player.x = 340;
                all->pos_player.y = 390;
                sfView_setCenter(view, (sfVector2f){all->xview, all->yview});
                sfView_setSize(view, (sfVector2f){1000, 500});
                sfRenderWindow_setView(all->w, view);
                c = 0;
            }
        }

        if (sfKeyboard_isKeyPressed(sfKeyDown)) {
            if ((all->pos_player.x >= 740 && all->pos_player.x <= 840) && all->pos_player.y == 895 && all->page == GAME7) {
                all->page = GAME1;
                all->noda = NULL;
                struct node *ne = malloc(sizeof(struct node));
                ne->s = all->s03;
                ne->t = all->t03;
                ne->pos_x = 0;
                ne->pos_y = 0;
                ne->scale = all->scale03;
                ne->val = GAME1;
                ne->next = NULL;
                all = addnode(ne, all);
                all->scale04.x = 1;
                all->scale04.y = 1;
                all->pos_player.x = 1710;
                all->pos_player.y = 880;
                sfView_setCenter(view, (sfVector2f){all->xview, all->yview});
                sfView_setSize(view, (sfVector2f){1000, 500});
                sfRenderWindow_setView(all->w, view);
                c = 0;
            }

        }

        if (sfKeyboard_isKeyPressed(sfKeyDown)) {
            if ((all->pos_player.x >= 310 && all->pos_player.x <= 510) && all->pos_player.y == 975 && all->page == GAME4) {
                all->page = GAME1;
                all->noda = NULL;
                struct node *ne = malloc(sizeof(struct node));
                ne->s = all->s03;
                ne->t = all->t03;
                ne->pos_x = 0;
                ne->pos_y = 0;
                ne->scale = all->scale03;
                ne->val = GAME1;
                ne->next = NULL;
                all = addnode(ne, all);
                all->scale04.x = 1;
                all->scale04.y = 1;
                all->pos_player.x = 1110;
                all->pos_player.y = 300;
                sfView_setCenter(view, (sfVector2f){all->xview, all->yview});
                sfView_setSize(view, (sfVector2f){1000, 500});
                sfRenderWindow_setView(all->w, view);
                c = 0;
            }
        }
        if (sfKeyboard_isKeyPressed(sfKeyDown)) {
            if ((all->pos_player.x >= 600 && all->pos_player.x <= 750) && all->pos_player.y == 900 && all->page == GAME5) {
                all->page = GAME1;
                all->noda = NULL;
                struct node *ne = malloc(sizeof(struct node));
                ne->s = all->s03;
                ne->t = all->t03;
                ne->pos_x = 0;
                ne->pos_y = 0;
                ne->scale = all->scale03;
                ne->val = GAME1;
                ne->next = NULL;
                all = addnode(ne, all);
                all->scale04.x = 1;
                all->scale04.y = 1;
                all->pos_player.x = 725;
                all->pos_player.y = 310;
                sfView_setCenter(view, (sfVector2f){all->xview, all->yview});
                sfView_setSize(view, (sfVector2f){1000, 500});
                sfRenderWindow_setView(all->w, view);
                c = 0;
            }
        }

        if (sfKeyboard_isKeyPressed(sfKeyDown)) {
            if ((all->pos_player.x >= 620 && all->pos_player.x <= 795) && all->pos_player.y == 900 && all->page == GAME6) {
                all->page = GAME1;
                all->noda = NULL;
                struct node *ne = malloc(sizeof(struct node));
                ne->s = all->s03;
                ne->t = all->t03;
                ne->pos_x = 0;
                ne->pos_y = 0;
                ne->scale = all->scale03;
                ne->val = GAME1;
                ne->next = NULL;
                all = addnode(ne, all);
                all->scale04.x = 1;
                all->scale04.y = 1;
                all->pos_player.x = 1425;
                all->pos_player.y = 390;
                sfView_setCenter(view, (sfVector2f){all->xview, all->yview});
                sfView_setSize(view, (sfVector2f){1000, 500});
                sfRenderWindow_setView(all->w, view);
                c = 0;
            }
        }

        if (sfKeyboard_isKeyPressed(sfKeyDown)) {
            if ((all->pos_player.x >= 575 && all->pos_player.x <= 690) && all->pos_player.y == 925 && all->page == GAME2) {
                all->page = GAME1;
                all->noda = NULL;
                struct node *ne = malloc(sizeof(struct node));
                ne->s = all->s03;
                ne->t = all->t03;
                ne->pos_x = 0;
                ne->pos_y = 0;
                ne->scale = all->scale03;
                ne->val = GAME1;
                ne->next = NULL;
                all = addnode(ne, all);
                all->scale04.x = 1;
                all->scale04.y = 1;
                all->pos_player.x = 680;
                all->pos_player.y = 500;
                sfView_setCenter(view, (sfVector2f){all->xview, all->yview});
                sfView_setSize(view, (sfVector2f){1000, 500});
                sfRenderWindow_setView(all->w, view);
                c = 0;
            }
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape) && all->page == GAME1 && all->scorehunter < 7) {
            struct node *ne = malloc(sizeof(struct node));
            usleep(200000);
            my_putstr("\n\n");
            ne->s = all->s06;
            ne->t = all->t06;
            ne->pos_x = all->xview - 330;
            ne->pos_y = all->yview - 260;
            all->scale06.x = 0.8;
            all->scale06.y = 0.8;
            ne->scale = all->scale06;
            ne->val = GAMEMENU;
            ne->next = NULL;
            all->ifgamemenu = 1;
            all = addnode(ne, all);
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape) && all->page != GAME1 && all->page != MENU && all->ifgamemenu == 0 && all->scorehunter < 7) {
            struct node *ne = malloc(sizeof(struct node));

            usleep(200000);
            my_putstr("\n\n");
            ne->s = all->s06;
            ne->t = all->t06;
            ne->pos_x = -150;
            ne->pos_y = -120;
            all->scale06.x = 2.2;
            all->scale06.y = 2.2;
            ne->scale = all->scale06;
            ne->val = GAMEMENU;
            ne->next = NULL;
            all = addnode(ne, all);
            all->ifgamemenu = 1;
        }

        if (sfKeyboard_isKeyPressed(sfKeyUp)) {
            if ((all->pos_player.x >= 320 && all->pos_player.x <= 350) && all->pos_player.y == 380 && all->page == GAME1) {
                all->noda = NULL;
                new->s = all->s07;
                new->t = all->t07;
                new->scale = all->scale07;
                new->pos_x = 100;
                new->pos_y = 0;
                new->val = GAME3;
                new->next = NULL;
                all = addnode(new, all);
                c = 0;
                all->page = GAME3;
                all->scale04.x = 3;
                all->scale04.y = 3;
                all->pos_player.x = 210;
                all->pos_player.y = 1100;
                sfView_setCenter(view, (sfVector2f){800, 550});
                sfView_setSize(view, (sfVector2f){2600, 1300});
                sfRenderWindow_setView(all->w, view);
            }

            if (all->pos_player.x >= 1090 && all->pos_player.x <= 1130 && all->pos_player.y == 300 && all->page == GAME1) {
                all->noda = NULL;
                new->s = all->s08;
                new->t = all->t08;
                new->scale = all->scale08;
                new->pos_x = 100;
                new->pos_y = 0;
                new->val = 0;
                new->next = NULL;
                all = addnode(new, all);
                c = 0;all->noda = NULL;
                new->s = all->s07;
                new->t = all->t07;
                new->scale = all->scale07;
                new->pos_x = 100;
                new->pos_y = 0;
                new->val = GAME3;
                new->next = NULL;
                all = addnode(new, all);
                all->page = GAME4;
                all->scale04.x = 3;all->noda = NULL;
                new->s = all->s07;
                new->t = all->t07;
                new->scale = all->scale07;
                new->pos_x = 100;
                new->pos_y = 0;
                new->val = GAME3;
                new->next = NULL;
                all = addnode(new, all);
                all->scale04.y = 3;
                all->pos_player.x = 400;
                all->pos_player.y = 975;
                sfView_setCenter(view, (sfVector2f){800, 550});
                sfView_setSize(view, (sfVector2f){2600, 1300});
                sfRenderWindow_setView(all->w, view);
            }


            if ((all->pos_player.x >= 670 && all->pos_player.x <= 710) && all->pos_player.y == 500 && all->page == GAME1) {
                all->noda = NULL;
                new->s = all->s05;
                new->t = all->t05;
                new->scale = all->scale05;
                new->pos_x = 100;
                new->pos_y = 0;
                new->val = 0;
                new->next = NULL;
                all = addnode(new, all);
                c = 0;
                all->page = GAME2;
                all->scale04.x = 3;
                all->scale04.y = 3;
                all->pos_player.x = 626;
                all->pos_player.y = 875;
                sfView_setCenter(view, (sfVector2f){800, 550});
                sfView_setSize(view, (sfVector2f){2600, 1300});
                sfRenderWindow_setView(all->w, view);
            }
            if ((all->pos_player.x >= 700 && all->pos_player.x <= 740) && all->pos_player.y == 300 && all->page == GAME1) {
                all->noda = NULL;
                new->s = all->s09;
                new->t = all->t09;
                new->scale = all->scale09;
                new->pos_x = 100;
                new->pos_y = 0;
                new->val = GAME5;
                new->next = NULL;
                all = addnode(new, all);
                c = 0;
                all->page = GAME5;
                all->scale04.x = 3;
                all->scale04.y = 3;
                all->pos_player.x = 675;
                all->pos_player.y = 900;
                sfView_setCenter(view, (sfVector2f){800, 550});
                sfView_setSize(view, (sfVector2f){2600, 1300});
                sfRenderWindow_setView(all->w, view);
            }

            if ((all->pos_player.x >= 1690 && all->pos_player.x <= 1740) && all->pos_player.y == 880 && all->page == GAME1) {
                all->noda = NULL;
                new->s = all->s11;
                new->t = all->t11;
                new->scale = all->scale11;
                new->pos_x = 100;
                new->pos_y = 0;
                new->val = GAME7;
                new->next = NULL;
                all = addnode(new, all);
                c = 0;
                all->page = GAME7;
                all->scale04.x = 3;
                all->scale04.y = 3;
                all->pos_player.x = 800;
                all->pos_player.y = 895;
                sfView_setCenter(view, (sfVector2f){800, 550});
                sfView_setSize(view, (sfVector2f){2600, 1300});
                sfRenderWindow_setView(all->w, view);
            }

            if ((all->pos_player.x >= 1400 && all->pos_player.x <= 1440) && all->pos_player.y == 380 && all->page == GAME1) {
                all->noda = NULL;
                new->s = all->s10;
                new->t = all->t10;
                new->scale = all->scale10;
                new->pos_x = 100;
                new->pos_y = 0;
                new->val = GAME6;
                new->next = NULL;
                all = addnode(new, all);
                c = 0;
                all->page = GAME6;
                all->scale04.x = 3;
                all->scale04.y = 3;
                all->pos_player.x = 720;
                all->pos_player.y = 900;
                sfView_setCenter(view, (sfVector2f){800, 550});
                sfView_setSize(view, (sfVector2f){2600, 1300});
                sfRenderWindow_setView(all->w, view);
            }

        }

        
        if (sfKeyboard_isKeyPressed(sfKeyUp) && all->page != MENU && all->ifgamemenu == 0 && all->page != GAME1 && all->action == RIEN)
        {
            if ((t1.microseconds / 1000000.0) > 0.1) {
                sfClock_restart(k);
                all = editlstup(all, 25);
                all = edituparea(all);
            }
        }
        if (sfKeyboard_isKeyPressed(sfKeyDown) && all->page != MENU && all->ifgamemenu == 0 && all->page != GAME1 && all->action == RIEN)
        {
            if ((t1.microseconds / 1000000.0) > 0.1) {
                sfClock_restart(k);
                all = editlstdown(all, 25);
                all = editdownarea(all);
            }
        }
        if (sfKeyboard_isKeyPressed(sfKeyLeft) && all->page != MENU && all->page != GAME1 && all->ifgamemenu == 0 && all->action == RIEN)
        {
            if ((t1.microseconds / 1000000.0) > 0.1) {
                sfClock_restart(k);
                all = editlstleft(all, 25);
                all = editleftarea(all);
            }
        }
        if (sfKeyboard_isKeyPressed(sfKeyRight) && all->page != MENU && all->page != GAME1 && all->ifgamemenu == 0 && all->action == RIEN)
        {
            if ((t1.microseconds / 1000000.0) > 0.1) {
                sfClock_restart(k);
                all = editlstright(all, 25);
                all = editrightarea(all);
            }
        }
        if (sfKeyboard_isKeyPressed(sfKeyUp) && all->page == GAME1 && limitations(all, 0, -10) == 0)
        {
            if ((t1.microseconds / 1000000.0) > 0.1) {
                sfClock_restart(k);
                if ((all->yview - 10) >= 250 && (all->pos_player.y <= 770)) {
                    all->yview = all->yview - 10;
                }
                sfView_setCenter(view, (sfVector2f){all->xview, all->yview});
                sfRenderWindow_setView(all->w, view);
                all = editlstup(all, 10);
                all = edituparea(all);
            }
        }
        if (sfKeyboard_isKeyPressed(sfKeyDown) && all->page == GAME1 && limitations(all, 0, 10) == 0)
        {
            if ((t1.microseconds / 1000000.0) > 0.1) {
                sfClock_restart(k);
                if ((all->yview <= 770) && (all->pos_player.y >= 250)) {
                    all->yview = all->yview + 10;
                }
                sfView_setCenter(view, (sfVector2f){all->xview, all->yview});
                sfRenderWindow_setView(all->w, view);
                all = editlstdown(all, 10);
                all = editdownarea(all);
            }
        }
        if (sfKeyboard_isKeyPressed(sfKeyLeft) && all->page == GAME1 && limitations(all, -10, 0) == 0)
        {
            if ((t1.microseconds / 1000000.0) > 0.1) {
                sfClock_restart(k);
                if ((all->xview - 10) >= 500 && (all->pos_player.x <= 1420)) {
                    all->xview = all->xview - 10;
                }
                sfView_setCenter(view, (sfVector2f){all->xview, all->yview});
                sfRenderWindow_setView(all->w, view);
                all = editlstleft(all, 10);
                all = editleftarea(all);
            }
        }
        if (sfKeyboard_isKeyPressed(sfKeyRight) && all->page == GAME1 && limitations(all, 10, 0) == 0)
        {
            if ((t1.microseconds / 1000000.0) > 0.1) {
                sfClock_restart(k);
                if ((all->xview + 10) <= 1420 && (all->pos_player.x >= 500)) {
                    all->xview = all->xview + 10;
                }
                sfView_setCenter(view, (sfVector2f){all->xview, all->yview});
                sfRenderWindow_setView(all->w, view);
                all = editlstright(all, 10);
                all = editrightarea(all);
            }
        }

        if (all->page != MENU && c == 0) {
            struct node *ne = malloc(sizeof(struct node));
            ne->s = all->s04;
            ne->t = all->t04;
            ne->pos_x = all->pos_player.x;
            ne->pos_y = all->pos_player.y;
            ne->scale = all->scale04;
            ne->area = all->player_L0;
            ne->areaint = AREAL0;
            ne->val = PLAYER;
            ne->next = NULL;
            c++;
            all = addnode(ne, all);
        }
        sfRenderWindow_clear(all->w, sfBlack);
        printlstch(all);
        // if (all->duréedial != 0)
        //     sleep(1);
        sfRenderWindow_display(all->w);
    }
}
