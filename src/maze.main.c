/*
 * E89 Pedagogical & Technical Lab
 * project:     Maze
 * created on:  2024-01-17 - 09:19 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: Main for maze function
 */

#include "../include/maze.h"
#include <unistd.h>
#include <stdlib.h>

static int do_maze(struct maze_important *maze)
{
    int res;
    int dir_start;
    struct player player;

    dir_start = place_player(maze, &player);
    if (dir_start == -1) {
        write(1, "Start is not on a wall.\n", 24);
        return (1);
    }
    if (gauche(maze, &player)) {
        write(1, "No solution to maze.\n", 21);
        res = 1;
    } else {
        write(1, maze->map, stu_strlen(maze->map));
        res = 0;
        propagation(maze, dir_start);
        write(1, "\ndistances to start:\n", 21);
        write(1, maze->map, stu_strlen(maze->map));
    }
    return (res);
}

static int conditions(struct maze_important *maze)
{
    if (calc(maze)) {
        return (1);
    }
    if (find_start_finish(maze)) {
        return (1);
    }
    if (do_maze(maze)) {
        return (1);
    }
    return (0);
}

int main (int ac, char **av)
{
    int res;
    struct maze_important maze;

    if (ac != 2) {
        write(1, "Wrong amount of arguments.\n", 27);
        return (1);
    }
    maze.map = read_map(av);
    if (!maze.map) {
        write(1, "Error while trying to read the file.\n", 37);
        return (1);
    }
    res = conditions(&maze);
    free(maze.map);
    return (res);
}
