/*
** EPITECH PROJECT, 2022
** convert any base to decimal
** File description:
** any_to_decimal
*/

#include <string.h>
#include <stdio.h>

char *my_revstr(char *str);

char calc(int nb)
{
    if (nb >= 0 && nb <= 9)
        return (nb + '0');
    else
        return (nb - 10 + 'A');
}

char *decimal_to_any(int nb, int base)
{
    char result[100];
    int i = 0;

    while (nb > 0) {
        result[i] = calc(nb % base);
        nb = nb / base;
        i++;
    }
    result[i] = '\0';
    return (my_revstr(result));
}
