/*
** EPITECH PROJECT, 2022
** convert decimal to any base
** File description:
** decimal_to_any
*/

#include <string.h>
#include <stdio.h>

int calc_1(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0');
    else
        return (c - 'A' + 10);
}

int any_to_decimal(char *str, int base)
{
    int len = strlen(str);
    int tmp = 1;
    int result = 0;

    for (int i = len - 1; i >= 0; i--) {
        result += calc_1(str[i]) * tmp;
        tmp = tmp * base;
    }
    return (result);
}
