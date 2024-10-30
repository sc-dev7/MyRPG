/*
** EPITECH PROJECT, 2022
** B-CPE-100-MAR-1-1-cpoolday06-yanis.denat
** File description:
** my_strcpy.c
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
