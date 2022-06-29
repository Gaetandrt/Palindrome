/*
** EPITECH PROJECT, 2022
** we we we
** File description:
** main
*/

#include "palindrome.h"

void overflow(char *str)
{
    int nb = atoi(str);

    if (nb < 0)
        exit(84);
}

void get_n_list(palindrome_t *palindrome, list_t **list)
{
    if (is_palindrome_base(decimal_to_any(palindrome->nb, palindrome->base))
    == false) {
        printf("invalid argument\n");
        exit(84);
    }
    for (int i = 1; i <= palindrome->nb; i++)
        process_palin(palindrome, list, i);
}

int main(int ac, char **av)
{
    struct palindrome_s palindrome = {0, 0, 0, 0, 10, 0, 100, 0};
    list_t *list = malloc(sizeof(list_t));

    list->next = NULL;
    error_handling(ac, av);
    av = format_av(av, ac, &palindrome);
    get_flags(ac, av, &palindrome);
    if (palindrome.p_flag == 1)
        get_n_list(&palindrome, &list);
    else if (palindrome.n_flag == 1)
        find_palin(&palindrome);
    else
        exit(84);
    if (linked_list_len(&list->next) > 1)
        sort_list(linked_list_len(&list->next) + 1, &list->next);
    result_handling(&list, &palindrome);
    print_list(&list->next, &palindrome);
    return (0);
}
