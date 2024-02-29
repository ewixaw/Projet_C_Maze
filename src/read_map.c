/*
 * E89 Pedagogical & Technical Lab
 * project:     Maze
 * created on:  2024-01-16 - 11:54 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: get the map from a file to a usable char *
 */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static int count_char_file(char *av)
{
    char *buffer;
    int count;
    int nb_read;
    int fd;

    fd = open(av, O_RDONLY);
    buffer = malloc(sizeof(char) * 25);
    if (!buffer) {
        return (-1);
    }
    count = 0;
    nb_read = read(fd, buffer, 25);
    while (nb_read != 0) {
        count = count + nb_read;
        nb_read = read(fd, buffer, 25);
        if (nb_read == -1) {
            free(buffer);
            return (-1);
        }
    }
    free(buffer);
    close(fd);
    return (count);
}

static void bye_bye(int fd, char *buffer)
{
    close(fd);
    free(buffer);
}

char *read_map(char **av)
{
    int fd;
    char *buffer;
    int nb_char_file;
    int verif;

    nb_char_file = count_char_file(av[1]);
    if (nb_char_file == -1) {
        return (NULL);
    }
    fd = open(av[1], O_RDONLY);
    if (fd == -1) {
        return (NULL);
    }
    buffer = malloc(sizeof(char) * nb_char_file + 1);
    if (!buffer) {
        close(fd);
        return (NULL);
    }
    verif = read(fd, buffer, nb_char_file);
    if (verif == -1) {
        bye_bye(fd, buffer);
        return (NULL);
    }
    buffer[verif] = '\0';
    return (buffer);
}
