/*
** Léonard Verschuere, 2023
** side_project
** test_my_to_do.c
*/

#include <stdio.h>
#include <string.h>
#include "criterion/criterion.h"
#include <criterion/redirect.h>
#include "../include/to_do.h"

Test(print_usage, test_print_usage)
{
    int result = print_usage();
    cr_assert_eq(result, 0);
}

Test(print_list, test_print_list)
{
    char list_file[] = "unit_test_text.txt";
    int result = print_list(list_file);
    cr_assert_eq(result, 0);
}

Test(init_del_task, test_init_del_task)
{
    char list_file[] = "unit_test_text.txt";
    char task[] = "Test task";
    int result = init_del_task(list_file, task);
    cr_assert_eq(result, 0);
}

Test(add_task, test_add_task)
{
    char list_file[] = "unit_test_text.txt";
    char task[] = "Test task";
    int result = add_task(list_file, task);
    cr_assert_eq(result, 0);
}

Test(str_to_words, test_str_to_words)
{
    char *s = "This is a test";
    char **result = str_to_words(s, ' ');
    cr_assert(result != NULL);
    cr_assert(strcmp(result[0], "This") == 0);
    cr_assert(strcmp(result[1], "is") == 0);
    cr_assert(strcmp(result[2], "a") == 0);
    cr_assert(strcmp(result[3], "test") == 0);
}

Test(count_words, test_count_words)
{
    char *s = "This is a test";
    int result = count_words(s, ' ');
    cr_assert_eq(result, 4);
}

Test(my_strndup, test_my_strndup)
{
    char *s = "This is a test";
    char *result = my_strndup(s, 0, 4);
    cr_assert(strcmp(result, "This") == 0);
}
