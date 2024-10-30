/*
** EPITECH PROJECT, 2022
** B-CPE-100-MAR-1-1-cpoolday07-yanis.denat
** File description:
** my_putchar.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
