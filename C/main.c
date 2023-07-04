/*
** Leonard Verschuere, 2023
** side_project
** main.c
*/

#include <stdio.h>
#include <string.h>
#include "to_do.h"

int main(int argc, char **argv)
{
    if (argc < 2 || argc > 4 || strcmp(argv[1], "-h") == 0)
        return (print_usage());
    if (strcmp(argv[1], "list") == 0)
        return (print_list(argv[2]));
    if (strcmp(argv[1], "add") == 0)
        return (add_task(argv[2], argv[3]));
    if (strcmp(argv[1], "del") == 0)
        return (init_del_task(argv[2], argv[3]));
    return (0);
}
