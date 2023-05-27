/*
** Léonard Verschuere, 2023
** side_project
** deletion.c
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include "to_do.h"

int del_task(char **list, char *filename, int size, int marked)
{
    int fd = open(filename, O_RDWR | O_CREAT, 0);
    int test = 0;

    for (int i = 0; list[i] != NULL; i++) {
        if (i != marked) {
            write(fd, list[i], strlen(list[i]));
            write(fd, "\n", 1);
        test += strlen(list[i]) + 1;
        }
    }
    for (int i = test + 1; i != size; i++)
        write(fd, "\0", 1);
    close(fd);
    return (print_list(filename));
}

int identify_task(char *task, char *filename, int size)
{
    char **list = NULL;
    char *str = NULL;
    int marked = -1;
    int fd = open(filename, O_RDWR | O_CREAT, 0);
    char *buffer = malloc(sizeof(char) * size);

    if (read(fd, buffer, size) == 0)
        return 84;
    list = str_to_words(buffer, '\n');
    for (int i = 0; list[i] != NULL; i++) {
        str = list[i];
        if (strcmp(str, task) == 0) {
            marked = i;
            break;
        }
    }
    if (marked == -1) {
        printf("Task \"%s\" not found\n", task);
        return 84;
    }
    close(fd);
    free(buffer);
    return (del_task(list, filename, size, marked));
}

int init_del_task(char *filename, char *task)
{
    int fd = open(filename, O_RDONLY);
    struct stat st;
    char *buffer = NULL;
    int size = 0;

    stat(filename, &st);
    if (fd == -1) {
        printf("\"%s\" could not be opened, please make sure it's a real file.\n", filename);
        return 84;
    }
    buffer = malloc(sizeof(char) * st.st_size + 1);
    if (read(fd, buffer, st.st_size) == 0) {
        printf("No task to do\n");
        return 84;
    }
    size = st.st_size;
    close(fd);
    free(buffer);
    return (identify_task(task, filename, size));
}
