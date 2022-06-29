/*
** EPITECH PROJECT, 2022
** file for error handling
** File description:
** error_handling
*/

#include "palindrome.h"

void error_handling_bis(char **av, int i)
{
    if (av[i + 1] != NULL)
        if (av[i + 2] != NULL && av[i + 2][0] != '-') {
            printf("invalid argument\n");
            exit(84);
    }
}

void m_flag_error(char **av, int i)
{
    if (strcmp(av[i], "-imin") == 0 || strcmp(av[i], "-imax") == 0)
        return;
    else {
        printf("invalid argument(s)\n");
        exit(84);
    }
}

int my_str_isdigit(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (isdigit(str[i]) == 0) {
            printf("invalid argument\n");
            exit(84);
        }
    return (0);
}

void error_handling_2(palindrome_t *palindrome)
{
    if (palindrome->imin > palindrome->imax) {
        printf("invalid argument\n");
        exit(84);
    }
}

void error_handling(int ac, char **av)
{
    if (ac == 1) {
        printf("Usage: ./palindrome [nbr]\n");
        exit(84);
    }
    for (int i = 0; av[i] != NULL; i++) {
        if (av[i][0] == '-' && av[i + 1] != NULL) {
            error_handling_bis(av, i);
            my_str_isdigit(av[i + 1]);
            overflow(av[i + 1]);
        }
        if (av[i][0] == '-' && av[i + 1] == NULL) {
            printf("invalid argument\n");
            exit(84);
        }
    }
}
