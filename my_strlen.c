/*
** EPITECH PROJECT, 2022
** B-CPE-100-MAR-1-1-cpoolday04-yanis.denat
** File description:
** my_strlen.c
*/

int my_strlen(char const *str)
{
    int i = 0;
    for (; str[i] != '\0'; i++);
    return i;
}
