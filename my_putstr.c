/*
** EPITECH PROJECT, 2022
** B-CPE-100-MAR-1-1-cpoolday04-yanis.denat
** File description:
** my_putstr.c
*/

#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return 0;
}
