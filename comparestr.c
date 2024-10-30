/*
** EPITECH PROJECT, 2022
** comp
** File description:
** str
*/

#include "my.h"

int ifsamechar(char *str1, char *str2)
{
    int a = my_strlen(str1);
    int b = my_strlen(str2);
    if (a == b)
        return SUCCESS;
    return FAILED;
}

int comparestr(char *str1, char *str2)
{
    if (ifsamechar(str1, str2) == FAILED)
        return FAILED;
    int nb = 0;
    while (str1[nb] != '\0') {
        if (str1[nb] == str2[nb]) {
            nb++;
        } else {
            return FAILED;
        }
    }
    return SUCCESS;
}
