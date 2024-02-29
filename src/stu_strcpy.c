/*
 * E89 Pedagogical & Technical Lab
 * project:     Maze
 * created on:  2024-01-22 - 10:33 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: strcpy function
 */

char *stu_strcpy(char *dest, const char *src)
{
    int counter;

    counter = 0;
    while (src[counter] != '\0') {
        dest[counter] = src[counter];
        counter = counter + 1;
    }
    dest[counter] = '\0';
    return (dest);
}
