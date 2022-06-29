/*
** EPITECH PROJECT, 2021
** pushswap main file epitech project
** File description:
** main file for pushswap
*/

#include "palindrome.h"
#include <stdio.h>
#include <stdlib.h>

int min(int x, int y)
{
    return (x < y ? x : y);
}

void min_find(list_t **la, list_t **lb, list_t **tail)
{
    int min_val = (*la)->pal;

    for (list_t *tmp = *la; tmp != NULL; tmp = tmp->next) {
        min_val = min(min_val, tmp->pal);
    }
    while ((*la)->pal != min_val) {
        swap_end(la, tail);
    }
    pb_function(la, lb);
}

void sort_list(int ac, list_t **la)
{
    list_t *lb = malloc(sizeof(list_t));
    list_t *tail = NULL;
    list_t *temp = NULL;

    lb->next = NULL;
    temp = *la;
    for (; temp->next; temp = temp->next)
        continue;
    tail = temp;
    for (int i = 0; i < ac - 1; i++)
        min_find(la, &lb, &tail);
    for (int i = 0; i < ac - 1; i++)
        pa_function(la, &lb);
    free(lb);
}
