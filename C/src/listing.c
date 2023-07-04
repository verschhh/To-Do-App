/*
** Léonard Verschuere, 2023
** side_project
** listing.c
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "to_do.h"

int print_list(char *filename)
{
    int fd = open(filename, O_RDONLY);
    struct stat st;
    char *buffer = NULL;

    stat(filename, &st);
    if (fd == -1) {
        printf("\"%s\" could not be opened, please make sure it's a real file.\n", filename);
        return 84;
    }
    buffer = malloc(sizeof(char) * st.st_size + 1);
    if (read(fd, buffer, st.st_size) == 0) {
        printf("No task to do\n");
        return 0;
    }
    printf("Here is your To-Do-List:\n%s", buffer);
    free(buffer);
    close(fd);
    return 0;
}
