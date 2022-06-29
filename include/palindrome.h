/*
** EPITECH PROJECT, 2022
** palindrome
** File description:
** palindrome
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#ifndef PALINDROME_H_
    #define PALINDROME_H_

//LINKED LIST WITH ALL PALINDROME FIND
typedef struct list_s {
    int nb;
    int pal;
    int iter;
    struct list_s *next;
} list_t;

//STRUCT WITH FLAG ARGUMENTS
typedef struct palindrome_s {
    bool n_flag;
    bool p_flag;
    int nb;
    int palin;
    int base;
    int imin;
    int imax;
    bool found;
} palindrome_t;

//PROGRAM FUNCTIONS
void help(void);
void overflow(char *str);
bool is_palindrome(int nb);
bool is_palindrome_base(char *str);
void m_flag_error(char **av, int i);
void error_handling(int ac, char **av);
int palindrome_calcul(int nb, int base);
void find_palin(palindrome_t *palindrome);
void print_1(list_t **head, palindrome_t *palindrome);
void print_2(list_t **head, palindrome_t *palindrome);
void print_3(list_t **head, palindrome_t *palindrome);
void add_list(list_t **head, int pal, int iter, int nb);
void result_handling(list_t **list, palindrome_t *palindrome);
char **format_av(char **av, int ac, palindrome_t *palindrome);
void get_flags(int ac, char **av, struct palindrome_s *palindrome);
void error_handling_2(palindrome_t *palindrome);
void process_palin(palindrome_t *palindrome, list_t **head, int i);

//LIB FUNCTIONS
char *my_itoa(int nb);
char *my_revstr(char *str);
char *decimal_to_any(int nb, int base);
int any_to_decimal(char *str, int base);
void print_list(list_t **head, palindrome_t *palindrome);

//SORT LINKED LIST FUNCTIONS
void sort_list(int ac, list_t **la);
void remove_first_node(list_t **head);
int linked_list_len(list_t **list);
void pb_function(list_t **la, list_t **lb);
void pa_function(list_t **la, list_t **lb);
void swap_end(list_t **head, list_t **tail);
void min_find(list_t **la, list_t **lb, list_t **tail);

#endif /* !PALINDROME_H_ */
