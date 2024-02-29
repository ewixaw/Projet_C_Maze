/*
 * E89 Pedagogical & Technical Lab
 * project:     Maze
 * created on:  2024-01-15 - 11:36 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: calc height and width of a maze
 */

#include <unistd.h>
#include "../include/maze.h"

static int not_map(char symbole)
{
    char *liste;
    int cnt;
    int ok;

    liste = "#.SG";
    cnt = 0;
    ok = 1;
    while (liste[cnt] != '\0') {
        if (liste[cnt] == symbole) {
            ok = 0;
        }
        cnt = cnt + 1;
    }
    return (ok);
}

static void message(int w, int h)
{
    write(1, "width: ", 7);
    print_base10(w);
    write(1, ", height: ", 10);
    print_base10(h);
    write(1, "\n", 1);
}

static int real_maze(struct maze_important *maze)
{
    int cnt;

    cnt = 1;
    while (maze->map[cnt] != '\0') {
        if ((cnt % (maze->width + 1)) == maze->width &&
            (maze->map[cnt] != '\n' && maze->map[cnt] != '\0')) {
            write(1, "Given file is not a correct maze.\n", 34);
            return (1);
        }
        cnt = cnt + 1;
    }
    return (0);
}

int calc (struct maze_important *maze)
{
    int cnt;

    maze->width = 0;
    maze->height = 0;
    cnt = 0;
    while (maze->map[cnt] != '\0') {
        if (not_map(maze->map[cnt])) {
            return (1);
        }
        while (maze->map[cnt] != '\n') {
            maze->width = maze->width + 1;
            cnt = cnt + 1;
        }
        if (maze->map[cnt] == '\n') {
            maze->height = maze->height + 1;
        }
        cnt = cnt + 1;
    }
    maze->width = maze->width / maze->height;
    if (real_maze(maze)) {
        return (1);
    }
    message(maze->width, maze->height);
    return (0);
}
