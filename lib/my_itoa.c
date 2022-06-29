/*
** EPITECH PROJECT, 2022
** convert an int into a string
** File description:
** my_itoa
*/

#include <stdlib.h>

char *my_itoa(int nb)
{
    int i = 0;
    int j = 0;
    char *str = malloc(sizeof(char) * 12);

    if (nb < 0) {
        str[i] = '-';
        i++;
        nb = -nb;
    }
    for (; nb > 0; nb = nb / 10)
        str[i++] = nb % 10 + '0';
    str[i] = '\0';
    for (j = 0; j < i / 2; j++) {
        str[j] ^= str[i - j - 1];
        str[i - j - 1] ^= str[j];
        str[j] ^= str[i - j - 1];
    }
    return (str);
}
