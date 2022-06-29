/*
** EPITECH PROJECT, 2021
** algorithme file
** File description:
** algo
*/

#include "palindrome.h"
#include <stdlib.h>

void swap_end(list_t **head, list_t **tail)
{
    (*tail)->next = *head;
    *tail = (*tail)->next;
    *head = (*head)->next;
    (*tail)->next = NULL;
}

void pb_function(list_t **la, list_t **lb)
{
    list_t *new_node = malloc(sizeof(list_t));

    new_node->nb = (*la)->nb;
    new_node->pal = (*la)->pal;
    new_node->iter = (*la)->iter;
    new_node->next = *lb;
    *lb = new_node;
    remove_first_node(la);
}

void pa_function(list_t **la, list_t **lb)
{
    list_t *new_node = malloc(sizeof(list_t));

    new_node->nb = (*lb)->nb;
    new_node->pal = (*lb)->pal;
    new_node->iter = (*lb)->iter;
    new_node->next = *la;
    *la = new_node;
    remove_first_node(lb);
}

void remove_first_node(list_t **head)
{
    list_t *to_remove = *head;
    *head = (*head)->next;
    free(to_remove);
}
