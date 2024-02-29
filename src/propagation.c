/*
 * E89 Pedagogical & Technical Lab
 * project:     Maze
 * created on:  2024-01-22 - 10:37 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: propagation function
 */

#include <stdlib.h>
#include "../include/maze.h"

static int nb_chemins(const char *map)
{
    int cnt;
    int nb_chemins;

    cnt = 0;
    nb_chemins = 0;
    while (map[cnt] != '\0') {
        if (map[cnt] == '.' || map[cnt] == ' ') {
            nb_chemins = nb_chemins + 1;
        }
        cnt = cnt + 1;
    }
    return (nb_chemins);
}

int is_chemin(char charac)
{
    if (charac == '.' || charac == ' ') {
        return (1);
    } else {
        return (0);
    }
}

void chg_vls(struct maze_important *maze, int **tab,
             struct position *posi, int ind)
{
    (*tab)[ind + posi->nb] = posi->near;
    maze->map[posi->near] = '0' +
        ((maze->map[posi->pos] - '0' + 1) % 10);
    posi->nb = posi->nb + 1;
}

int extension(struct maze_important *maze, int **tab,
              struct position *posi, int ind)
{
    posi->nb = 0;
    posi->near = posi->pos + 1;
    if (is_chemin(maze->map[posi->near]) == 1) {
        chg_vls(maze, tab, posi, ind);
    }
    posi->near = posi->pos - 1;
    if (is_chemin(maze->map[posi->near]) == 1) {
        chg_vls(maze, tab, posi, ind);
    }
    posi->near = posi->pos + maze->width + 1;
    if (posi->near < (maze->width + 1) * maze->height  &&
        is_chemin(maze->map[posi->near]) == 1) {
        chg_vls(maze, tab, posi, ind);
    }
    posi->near = posi->pos - maze->width - 1;
    if (posi->near > 0 && is_chemin(maze->map[posi->near]) == 1) {
        chg_vls(maze, tab, posi, ind);
    }
    return (posi->nb);
}

int propage(struct maze_important *maze, int **tab, int debut, int fin)
{
    int nb;
    int res;
    int indice;
    struct position posi;

    nb = 0;
    indice = fin;
    while (debut < fin) {
        posi.pos = (*tab)[debut];
        res = extension(maze, tab, &posi, indice);
        nb = nb + res;
        indice = indice + res;
        debut = debut + 1;
    }
    return (nb);
}

static int after_start(struct maze_important *maze, int dir_start)
{
    if (dir_start == Est) {
        return (maze->start + 1);
    }
    if (dir_start == Ouest) {
        return (maze->start - 1);
    }
    if (dir_start == Sud) {
        return (maze->start + maze->width + 1);
    }
    if (dir_start == Nord) {
        return (maze->start - maze->width - 1);
    }
    return (0);
}

void int_memset(int *array, int len)
{
    int cnt;

    cnt = 0;
    while (cnt < len) {
        array[cnt] = 0;
        cnt = cnt + 1;
    }
}

int propagation(struct maze_important *maze, int dir_start)
{
    int *tab;
    int chemins;
    int all;
    int old;
    int new;

    chemins = nb_chemins(maze->map);
    tab = malloc(sizeof(int) * chemins);
    if (!tab) {
        return (1);
    }
    int_memset(tab, chemins);
    all = 0;
    old = 1;
    new = -1;
    tab[0] = after_start(maze, dir_start);
    maze->map[tab[0]] = '1';
    while (new != 0) {
        new = propage(maze, &tab, all, (all + old));
        all = all + old;
        old = new;
    }
    free(tab);
    return (0);
}
