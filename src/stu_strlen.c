/*
 * E89 Pedagogical & Technical Lab
 * project:     Maze
 * created on:  2024-01-16 - 12:25 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: stu_strlen function
 */

unsigned int stu_strlen(const char *str)
{
    int counter;

    counter = 0;
    while (str[counter] != '\0') {
        counter = counter + 1;
    }
    return (counter);
}
