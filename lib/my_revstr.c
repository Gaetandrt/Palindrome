/*
** EPITECH PROJECT, 2022
** reverse a string
** File description:
** my_revstr
*/

#include <string.h>
#include <stdlib.h>

char *my_revstr(char *str)
{
    int i = 0;
    int len = strlen(str);
    char *result = malloc(sizeof(char) * len + 1);

    while (len != 0) {
        result[i] = str[len - 1];
        len--;
        i++;
    }
    result[i] = '\0';
    return (result);
}
