/*
** EPITECH PROJECT, 2022
** To_Do_App
** File description:
** print_usage.c
*/

#include "to_do.h"
#include <stdio.h>

int print_usage(void)
{
    printf("Usage:\n./to_do_app list \"[File name]\"\n");
    printf("\tWill show you the list of added task\n");
    printf("./to_do_app add \"[File name]\" \"[task]\"\n");
    printf("\tWill add a take to the list\n");
    printf("./to_do_app del \"[File name]\" \"[task]\"\n");
    printf("\tWill remove a task from the list\n");
    return (0);
}