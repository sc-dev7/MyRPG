/*
** EPITECH PROJECT, 2022
** B-CPE-100-MAR-1-1-cpoolday03-yanis.denat
** File description:
** my_put_nbr.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void put_error(int i)
{
    long nb2 = i;
    if (nb2 == -2147483648)
        my_putstr("-2147483648");
    if (nb2 == 2147483647)
        my_putstr("2147483647");
}

int my_put_nbr(int nb)
{
    int a = 0;
    int b = 0;
    int count = 0;
    int allocate_nb = 0;

    if (nb > -2147483648 && nb < 2147483647) {
        if (nb < 0) {
            my_putchar('-');
            nb = nb * -1;
        }
        if (nb >= 10) {
            my_put_nbr(nb / 10);
        }
        my_putchar((nb % 10) + 48);
    } else
        put_error(nb);
}
