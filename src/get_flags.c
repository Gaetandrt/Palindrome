/*
** EPITECH PROJECT, 2022
** get all the flags arguments and put it into the struct palindrome
** File description:
** get_flags
*/

#include "palindrome.h"

void b_error(char **av, int i)
{
    if ((strlen(av[i + 1]) > 1 && strcmp(av[i + 1], "10") != 0)
    || strcmp(av[i + 1], "0") == 0) {
        printf("invalid argument\n");
        exit(84);
    }
}

void palin_set(char **av, palindrome_t *palindrome, int i)
{
    palindrome->palin = atoi(av[i + 1]);
    palindrome->n_flag = true;
}

void switch_case(int opt, char **av, palindrome_t *palindrome, int i)
{
    switch (opt) {
    case 'h':
        help();
        break;
    case 'n':
        palin_set(av, palindrome, i);
        break;
    case 'p':
        palindrome->nb = atoi(av[i + 1]);
        palindrome->p_flag = true;
        break;
    case 'b':
        b_error(av, i);
        palindrome->base = atoi(av[i + 1]);
        break;
    }
}

void get_flags(int ac, char **av, struct palindrome_s *palindrome)
{
    int opt = 0;

    for (int i = 1; (opt = getopt(ac, av, "nhpbi")) != -1; i += 2)
        if (opt != 'n' && opt != 'h' && opt != 'p' && opt != 'b' &&
        opt != 'i')
            exit(84);
        else
            switch_case(opt, av, palindrome, i);
    if ((palindrome->n_flag == false && palindrome->p_flag == false) ||
    (palindrome->n_flag == true && palindrome->p_flag == true)) {
        printf("invalid argument\n");
        exit(84);
    }
    error_handling_2(palindrome);
}
