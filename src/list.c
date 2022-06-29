/*
** EPITECH PROJECT, 2022
** all the function needed for the linked list
** File description:
** list
*/

#include "palindrome.h"

int check_list_occ(list_t **list, int nb)
{
    list_t *tmp = *list;

    tmp = tmp->next;
    while (tmp != NULL) {
        if (tmp->pal == nb)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

void add_list(list_t **head, int pal, int iter, int nb)
{
    list_t *tmp = *head;
    list_t *new = malloc(sizeof(list_t));

    if (check_list_occ(head, pal) == 1) {
        free(new);
        return;
    }
    new->pal = pal;
    new->iter = iter;
    new->nb = nb;
    new->next = NULL;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
}
