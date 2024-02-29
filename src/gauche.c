/*
 * E89 Pedagogical & Technical Lab
 * project:     Maze
 * created on:  2024-01-17 - 09:25 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: tenir la gauche
 */

#include "../include/maze.h"

static int avancer(struct player *player, struct maze_important *maze,
                   int width)
{
    if (player->ori == Est) {
        player->pos = player->pos + 1;
    }
    if (player->ori == Ouest) {
        player->pos = player->pos - 1;
    }
    if (player->ori == Sud) {
        player->pos = player->pos + width + 1;
    }
    if (player->ori == Nord) {
        player->pos = player->pos - width - 1;
    }
    if (maze->map[player->pos] == 'S') {
        return (1);
    }
    maze->map[player->pos] = ' ';
    return (0);
}

static int mur(int pos, enum direction dir, char *map, int width)
{
    if (dir == Est) {
        return (map[pos + 1] == '#');
    }
    if (dir == Ouest) {
        return (map[pos - 1] == '#');
    }
    if (dir == Sud) {
        return (map[pos + width + 1] == '#');
    }
    if (dir == Nord) {
        return (map[pos - width - 1] == '#');
    }
    return (-1);
}

int gauche(struct maze_important *maze, struct player *player)
{
    int dir_gauche;

    while (player->pos != maze->finish) {
        dir_gauche = (player->ori + 3) % 4;
        if (!mur(player->pos, dir_gauche, maze->map, maze->width)) {
            player->ori = dir_gauche;
            if (avancer(player, maze, maze->width)) {
                return (1);
            }
        } else if (mur(player->pos, dir_gauche, maze->map, maze->width)
                   && !mur(player->pos, player->ori, maze->map,
                           maze->width)) {
            if (avancer(player, maze, maze->width)) {
                return (1);
            }
        } else if (mur(player->pos, dir_gauche, maze->map, maze->width)
                   && mur(player->pos, player->ori, maze->map,
                           maze->width)) {
            player->ori = (player->ori + 1) % 4;
        }
    }
    maze->map[player->pos] = 'G';
    return (0);
}
