/*
 * E89 Pedagogical & Technical Lab
 * project:     Maze
 * created on:  2024-01-26 - 13:00 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: coords to index function
 */

int coords_to_idx(int x, int y, int width)
{
    int index;

    if (x > width) {
        return (-1);
    }
    index = ((width + 1) * y) + x;
    return (index);
}
