/*
** EPITECH PROJECT, 2022
** return the len of a linked list
** File description:
** linked_list_len
*/

#include "palindrome.h"

int linked_list_len(list_t **list)
{
    list_t *tmp = *list;
    int i = 0;

    if (tmp == NULL)
        return (0);
    while (tmp->next != NULL) {
        i++;
        tmp = tmp->next;
    }
    return (i);
}
