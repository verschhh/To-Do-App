/*
** Léonard Verschuere, 2023
** side_project
** addition.c
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include "to_do.h"

int add_task(char *filename, char *task)
{
    int fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 0);

    write(fd, task, strlen(task));
    write(fd, "\n", 1);
    close(fd);
    return (print_list(filename));
    return 0;
}