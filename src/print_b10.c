/*
 * E89 Pedagogical & Technical Lab
 * project:     Maze
 * created on:  2024-01-16 - 11:48 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: print base 10 function
 */

#include <unistd.h>

static void tc_putchar(char c)
{
    write(1, &c, 1);
}

static int nb_len(int nb)
{
    int count;

    count = 0;
    if (nb == 0) {
        return (1);
    }
    while (nb != 0) {
        nb = nb / 10;
        count = count + 1;
    }
    return (count);
}

static int get_digit(int nb, int index)
{
    int res;

    if (nb < 0) {
        nb = nb * -1;
    }
    while (index > 0) {
        nb = nb / 10;
        index = index - 1;
    }
    res = nb % 10;
    return (res);
}

int print_base10(int nb)
{
    int len_nb;
    int count;

    len_nb = nb_len(nb);
    count = len_nb;
    if (nb < 0) {
        tc_putchar('-');
        count = count + 1;
    }
    while (len_nb != 0) {
        tc_putchar('0' + get_digit(nb, len_nb-1));
        len_nb = len_nb - 1;
    }
    return (count);
}
