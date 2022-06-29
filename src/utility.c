/*
** EPITECH PROJECT, 2022
** utility function
** File description:
** utility
*/

#include "palindrome.h"

bool is_palindrome(int nb)
{
    char *nb_rev = my_revstr(my_itoa(nb));
    char *nb_str = my_itoa(nb);

    if (strcmp(nb_str, nb_rev) == 0)
        return (true);
    else
        return (false);
}

char **format_av(char **av, int ac, palindrome_t *palindrome)
{
    int i = 0;
    char **new_av = malloc(sizeof(char *) * (ac + 1));

    for (; i < ac; i++) {
        if (strcmp(av[i], "-imin") == 0) {
            new_av[i] = "-i";
            palindrome->imin = atoi(av[i + 1]);
        } else if (strcmp(av[i], "-imax") == 0) {
            new_av[i] = "-i";
            palindrome->imax = atoi(av[i + 1]);
        } else
            new_av[i] = av[i];
    }
    new_av[i] = NULL;
    return (new_av);
}

void print_list_bis(list_t **head, palindrome_t *palindrome)
{
    if (palindrome->imin == 0 && palindrome->imax != 100)
        print_2(head, palindrome);
    if (palindrome->imin != 0 && palindrome->imax != 100)
        print_1(head, palindrome);
}

void print_list(list_t **head, palindrome_t *palindrome)
{
    list_t *tmp = *head;

    if (palindrome->imax == 100 && palindrome->imin == 0) {
        while (tmp != NULL) {
            printf("%d leads to %d in %d iteration(s) in base %d\n",\
            tmp->pal, tmp->nb, tmp->iter, palindrome->base);
            tmp = tmp->next;
        }
    } else if (palindrome->imin != 0 && palindrome->imax == 100)
        print_3(head, palindrome);
    else
        print_list_bis(head, palindrome);
}

void help(void)
{
    printf("USAGE\n");
    printf("     ./palindrome -n number -p palindrome [-b base]");
    printf("[-imin i] [-imax i]\n\n");
    printf("DESCRIPTION\n");
    printf("     -n n        integer to be transformed (>=0)\n");
    printf("     -p pal      palindromic number to be obtained (incompatibl");
    printf("e with the -n\noption) (>=0)\n");
    printf("                 if defined, all fitting values of n will be");
    printf(" output\n");
    printf("     -b base     base in which the procedure will be executed");
    printf(" (1<b<=10) [def: 10]\n");
    printf("     -imin i     minimum number of iterations, included (>=0)");
    printf(" [def: 0]\n");
    printf("     -imax i     maximum number of iterations, included (>=0)");
    printf(" [def: 100]\n");
    exit(0);
}
