/*
** EPITECH PROJECT, 2022
** process palindrome and calcul the palindrome of a number
** File description:
** calcul
*/

#include "palindrome.h"

bool is_palindrome_base(char *str)
{
    char *nb_rev = my_revstr(str);

    if (strcmp(str, nb_rev) == 0)
        return (true);
    else
        return (false);
}

int palindrome_calcul(int nb, int base)
{
    char *nb_base_rev = my_revstr(decimal_to_any(nb, base));
    int nb_dec_rev = any_to_decimal(nb_base_rev, base);
    int result = nb_dec_rev + nb;

    return (result);
}

bool find_palin_bis(palindrome_t *palindrome, int calc, int iter)
{
    if (is_palindrome_base(decimal_to_any(calc, palindrome->base)) == true) {
        if (iter >= palindrome->imin && iter <= palindrome->imax) {
            printf("%d leads to %d in %d iteration(s) in base %d\n",
            palindrome->palin, calc, iter, palindrome->base);
            palindrome->found = true;
            return (true);
        }
    }
    return (false);
}

void find_palin(palindrome_t *palindrome)
{
    int calc = palindrome->palin;
    int iter = 0;

    while (1) {
        if (iter > palindrome->imax)
            break;
        if (find_palin_bis(palindrome, calc, iter) == true)
            exit(0);
        iter++;
        calc = palindrome_calcul(calc, palindrome->base);
    }
    printf("no solution\n");
    exit(0);
}

void process_palin(palindrome_t *palindrome, list_t **head, int i)
{
    int calc = i;
    int iter = 0;

    for (; calc <= palindrome->nb;) {
        if (is_palindrome_base(decimal_to_any(calc, palindrome->base)) == true
        && calc == palindrome->nb) {
            add_list(head, i, iter, palindrome->nb);
            palindrome->found = true;
        }
        iter++;
        calc = palindrome_calcul(calc, palindrome->base);
    }
}
