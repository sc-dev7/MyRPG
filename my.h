/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** Confirm
*/
#ifndef MY_MACRO
    #define MY_MACRO

    #include <ncurses.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <curses.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <time.h>
    #include <stdlib.h>
    #include <assert.h>
    #include <string.h>
    #include <errno.h>
    #include <sys/wait.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Transform.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <stddef.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #define FAILED -100
    #define SUCCESS 100
    #define SOUND 1
    #define NOSOUND 2
    #define MENU 3
    #define GAME1 4
    #define GAMEMENU 30
    #define DIALFEMME 31
    #define RIEN 32
    #define QUETEDEJAPARLE 33
    #define APRPARLER 34
    #define APRPARLER2 35
    #define APRJOUER 36
    #define PLAYER 5
    #define GAME2 6
    #define GAME3 7
    #define GAME4 8
    #define GAME5 9
    #define GAME6 27
    #define GAME7 28
    #define AREAR0 11
    #define AREAR1 12
    #define AREAR2 13
    #define AREAR3 14
    #define AREAL0 15
    #define AREAL1 16
    #define AREAL2 17
    #define AREAL3 18
    #define AREAT0 19
    #define AREAT1 20
    #define AREAT2 21
    #define AREAT3 22
    #define AREAB0 23
    #define AREAB1 24
    #define AREAB2 25
    #define AREAB3 26


struct node {
    sfSprite *s;
    sfTexture *t;
    sfIntRect area;
    int pos_x;
    int pos_y;
    sfVector2f scale;
    int val;
    int page;
    int areaint;
    struct node *next;
};

typedef struct {
    int xview;  //// 
    int yview;  ////
    int scorehunter; ////
    int duréedial; ////
    int quete; 
    int action; ////
    int ifgamemenu;
    sfRenderWindow *w;
    sfSprite *s01;
    sfSprite *s03;
    sfSprite *s02;
    sfSprite *s04;
    sfSprite *s05;
    sfSprite *s06;
    sfSprite *s07;
    sfSprite *s08;
    sfSprite *s09;
    sfSprite *s10;
    sfSprite *s11;
    sfSprite *s12;
    sfSprite *s13;
    sfSprite *s14;
    sfSprite *s15;
    sfSprite *s16;
    sfSprite *s17;
    sfSprite *s18;
    sfSprite *s19;
    sfSprite *s20;
    sfSprite *s21;
    sfSprite *s22;
    sfSprite *s23;
    sfTexture *t01;
    sfTexture *t02;
    sfTexture *t03;
    sfTexture *t04;
    sfTexture *t05;
    sfTexture *t06;
    sfTexture *t07;
    sfTexture *t08;
    sfTexture *t09;
    sfTexture *t10;
    sfTexture *t11;
    sfTexture *t12;
    sfTexture *t13;
    sfTexture *t14;
    sfTexture *t15;
    sfTexture *t16;
    sfTexture *t17;
    sfTexture *t18;
    sfTexture *t19;
    sfTexture *t20;
    sfTexture *t21;
    sfTexture *t22;
    sfTexture *t23;
    sfVector2f scale01;
    sfVector2f scale02;
    sfVector2f scale03;
    sfVector2f scale04;
    sfVector2f scale05;
    sfVector2f scale06;
    sfVector2f scale07;
    sfVector2f scale08;
    sfVector2f scale09;
    sfVector2f scale10;
    sfVector2f scale11;
    sfVector2f scale12;
    sfVector2f scale13;
    sfVector2f scale14;
    sfVector2f pos_player;
    sfVector2f pos_Aprjouer;
    sfVector2f pos_sound;
    sfVector2f pos_dialfemme;
    sfVector2f pos_Aprparler;
    sfIntRect player_R0;
    sfIntRect player_R1;
    sfIntRect player_R2;
    sfIntRect player_R3;
    sfIntRect player_L0;
    sfIntRect player_L1;
    sfIntRect player_L2;
    sfIntRect player_L3;
    sfIntRect player_B0;
    sfIntRect player_B1;
    sfIntRect player_B2;
    sfIntRect player_B3;
    sfIntRect player_T0;
    sfIntRect player_T1;
    sfIntRect player_T2;
    sfIntRect player_T3;
    struct node *noda;
    int sound;
    int pagebefgamemenu;
    int page;
} allim;

int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_isneg(int n);
int my_is_prime(int nb);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr (char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *tab, int size);
char *my_strcapitalize(char *str);
char *my_strcat(char *commande, char *path);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest,char const *src);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen (char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(const char *env, const char *str, int nb);
char *my_strncpy(char *dest,char const *src,int n);
char *my_strstr(char *str,char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
char *itoa(int nb);
#endif
