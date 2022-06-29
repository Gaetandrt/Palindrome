/*
** EPITECH PROJECT, 2022
** print functions
** File description:
** print
*/

#include "palindrome.h"

void print_3(list_t **head, palindrome_t *palindrome)
{
    list_t *tmp = *head;

    while (tmp != NULL) {
        if (tmp->iter >= palindrome->imin)
            printf("%d leads to %d in %d iteration(s) in base %d\n",
            tmp->pal, tmp->nb, tmp->iter, palindrome->base);
        tmp = tmp->next;
    }
}

void print_2(list_t **head, palindrome_t *palindrome)
{
    list_t *tmp = *head;

    while (tmp != NULL) {
        if (tmp->iter <= palindrome->imax)
            printf("%d leads to %d in %d iteration(s) in base %d\n",
            tmp->pal, tmp->nb, tmp->iter, palindrome->base);
        tmp = tmp->next;
    }
}

void print_1(list_t **head, palindrome_t *palindrome)
{
    list_t *tmp = *head;

    while (tmp != NULL) {
        if (tmp->iter <= palindrome->imax && tmp->iter >= palindrome->imin)
            printf("%d leads to %d in %d iteration(s) in base %d\n",
            tmp->pal, tmp->nb, tmp->iter, palindrome->base);
        tmp = tmp->next;
    }
}
