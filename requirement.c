/*
** EPITECH PROJECT, 2022
** project 2 synth pool requirement
** File description:
** requirement
*/

#include <stdio.h>

int my_factrec_synthesis(int nb)
{
    if (nb == 0 || nb == 1) {
        return (1);
    }
    if (nb < 0 || nb >= 13)
        return (0);
    return (nb * my_factrec_synthesis(nb - 1));
}

int my_squareroot_synthesis(int nb)
{
    int a = 0;
    int result = 0;

    if (nb == 0)
        return (0);
    if (nb == 1)
        return (1);
    if (nb < 0)
        return (-1);
    while (a < 46341) {
        a++;
        result = a * a;
        if (result == nb)
            return (a);
        if (result > nb)
            return (-1);
    }
}
