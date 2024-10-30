/*
** EPITECH PROJECT, 2022
** isaac
** File description:
** afzefe
*/

#pragma once

    #include <stdio.h>
    #include <unistd.h>
    #include<stdlib.h>
    #include<stdarg.h>
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

int comparestr(char *str1, char *str2);
struct bird fctevent(struct bird newbird, sfRenderWindow *window);
struct bird comparemouse(struct bird newbird, sfVector2i pos_mouse);
void did(struct bird newbird);
int num_alea(void);
struct bird createbird(void);
struct bird editbird(struct bird newbird);
struct bird editarea(struct bird newbird);
void cds(struct bird newbird, sfRenderWindow *window, sfSprite *sprite);
void cds2(struct bird newbird);
int nbligne(char *filepath);
char *returnbuf(char *filepath);
int wherebegin(char *filepath);
int nbcol(char *filepath);
char *makestr(int nb, char *filepath);
int verification(int lig, int col,char **tab, char *filepath);
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int d_flag(va_list ap, int nbc);
int c_flag(va_list ap, int nbc);
int s_flag(va_list ap, int nbc);
int s_flag_maj(va_list ap, int nbc);
int modulo_flag(va_list ap, int nbc);
int b_flag(va_list ap, int nbc);
int o_flag(va_list ap, int nbc);
int x_flag(va_list ap, int nbc);
int xe_flag(va_list ap, int nbc);
int u_flag(va_list ap, int nbc);
int e_flag(va_list ap, int nbc);
int f_flag(va_list ap, int nbc);
int p_flag(va_list ap, int nbc);
int l_flag(va_list ap, int nbc);
int plus_flag(va_list ap, int nbc);
int my_printf(const char *format, ...);
int forma(va_list ap, char c, int nbc, int *i);
int types(va_list ap, char c, int nbc, int *i);
char **strtotab(char *filepath);
int verifdiag(int lig, int col, char **tab);
int verifcote(int lig, int col, int i, char **tab);
