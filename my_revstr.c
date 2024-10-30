/*
** EPITECH PROJECT, 2022
** B-CPE-100-MAR-1-1-cpoolday06-yanis.denat
** File description:
** my_revstr.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen2(char *str)
{
    int i = 0;
    for (; str[i] != '\0'; i++);
    return i;
}

void my_swap2(char *a, char *b)
{
    char c;
    c = *a;
    *a = *b;
    *b = c;
}

char *my_revstr(char *str)
{
    int end = (my_strlen2(str) - 1);
    int first = 0;
    while (first < end) {
        my_swap2(&str[first], &str[end]);
        first++;
        end--;
    }
    return str;
}
