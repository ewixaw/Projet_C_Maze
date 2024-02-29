/*
 * E89 Pedagogical & Technical Lab
 * project:     Maze
 * created on:  2024-01-17 - 09:42 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: find the start function
 */

#include "../include/maze.h"

int find_start_finish(struct maze_important *maze)
{
    int cnt;

    cnt = 0;
    while (maze->map[cnt] != 'S') {
        cnt = cnt + 1;
    }
    maze->start = cnt;
    cnt = 0;
    while (maze->map[cnt] != 'G') {
        cnt = cnt + 1;
    }
    maze->finish = cnt;
    return (0);
}
