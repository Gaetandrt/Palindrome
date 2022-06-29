/*
** EPITECH PROJECT, 2022
** search if a palindrome has been found or not
** File description:
** result_handling
*/

#include "palindrome.h"

int find_min(list_t **head, int i, int min)
{
    for (list_t *tmp = *head;tmp->next != NULL; tmp = tmp->next)
        if (tmp->iter >= min)
            i++;
    if (i == 0)
        return (1);
    return (0);
}

int find_max(list_t **head, int i, int max)
{
    for (list_t *tmp = *head;tmp->next != NULL; tmp = tmp->next)
        if (tmp->iter <= max)
            i++;
    if (i == 0)
        return (1);
    return (0);
}

int find_max_min(list_t **head, palindrome_t *palindrome)
{
    int min = palindrome->imin;
    int max = palindrome->imax;
    int i = 0;

    if (max != 0)
        if (find_max(head, i, max) == 1)
            return (1);
    i = 0;
    if (min != 0) {
        if (find_min(head, i, min) == 1)
            return (1);
    }
    return (0);
}

void result_handling(list_t **head, palindrome_t *palindrome)
{
    if (palindrome->found == false) {
        printf("no solution\n");
        exit(0);
    }
    if (palindrome->imin != 0)
        if (find_max_min(head, palindrome) == 1) {
            printf("no solution\n");
            exit(0);
        }
}
