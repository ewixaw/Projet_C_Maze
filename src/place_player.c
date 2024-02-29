/*
 * E89 Pedagogical & Technical Lab
 * project:     Maze
 * created on:  2024-01-17 - 11:24 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: place the player in the maze
 */

#include "../include/maze.h"

int place_player (struct maze_important *maze, struct player *player)
{
    player->pos = maze->start;
    if (player->pos > 0 && player->pos < maze->width) {
        player->ori = Sud;
        return (Sud);
    }
    if (player->pos % (maze->width + 1) == 0) {
        player->ori = Est;
        return (Est);
    }
    if (player->pos > maze->width +
        ((maze->width + 1) * (maze->height - 2)) + 1 &&
        player->pos < maze->width +
        ((maze->width + 1) * (maze->height - 1)) - 1) {
        player->ori = Nord;
        return (Nord);
    }
    if ((player->pos - (maze->width - 1)) % (maze->width + 1) == 0) {
        player->ori = Ouest;
        return (Ouest);
    }
    return (-1); /*faire la vérification dans le main car sinon
                   cela veut dire que le start est dans le maze*/
}
