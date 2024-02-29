/*
 * E89 Pedagogical & Technical Lab
 * project:     Maze
 * created on:  2024-01-16 - 12:09 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: h file for maze project
 */

#ifndef MAZE_H_
#define MAZE_H_

enum direction {
    Nord,
    Est,
    Sud,
    Ouest,
};

struct maze_important {
    int width;
    int height;
    int start;
    int finish;
    char *map;
};

struct player {
    int pos;
    enum direction ori;
};

struct position {
    int pos;
    int near;
    int nb;
};

unsigned int stu_strlen(const char *str);
char *stu_strcpy(char *dest, const char *src);
int print_base10(int nb);
int coords_to_idx(int x, int y, int width);
int find_start_finish(struct maze_important *maze);
char *read_map(char **av);
int calc (struct maze_important *maze_s);
int place_player (struct maze_important *maze, struct player *player);
int gauche(struct maze_important *maze, struct player *player);
int propagation(struct maze_important *maze, int dir_start);

#endif
