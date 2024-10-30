/*
** EPITECH PROJECT, 2022
** B-CPE-100-MAR-1-1-cpoolday04-yanis.denat
** File description:
** my_getnbr.c
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int verifneg(char c, char operator)
{
    char d = '-';
    if (c == '-' && operator >= '0' && operator <= '9')
        return 1;
    return 0;
}

int is_num(char c)
{
    if (c >= '0' && c <= '9')
        return 0;
    return 1;
}

int is_break(char c, char c2)
{
    if (c >= '0' && c <= '9' && c2 < '0' || c2 > '9')
        return 1;
    return 0;
}

int convert_neg(int j, int tmp)
{
    if (j == 1) {
        tmp = tmp - (tmp * 2);
        return tmp;
    } else
    return tmp;
}

int my_getnbr(char const *str)
{
    int tmp = 0;
    int i = 0;
    int j = 0;
    while (str[i] != '\0') {
        if (verifneg(str[i], str[i + 1]) == 1)
            j = 1;
        if (is_num(str[i]) == 0) {
            tmp = tmp * 10;
            tmp = tmp + str[i] - '0';
        }
        if (is_break(str[i], str[i + 1]) == 1)
            break;
        i++;
    }
    tmp = convert_neg(j, tmp);
    return tmp;
}
