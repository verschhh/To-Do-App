/*
** Léonard Verschuere, 2023
** side_project
** my_str_to_word.c
*/

#include <stdio.h>
#include <stdlib.h>

char *my_strndup(char *s, int beginning, int end)
{
    char *new_s = NULL;
    int j = 0;
    int char_needed = 0;

    char_needed = end - beginning;
    new_s = malloc(sizeof(char) * (char_needed + 1));
    for (; beginning != end; beginning++) {
        new_s[j] = s[beginning];
        j++;
    }
    new_s[j] = '\0';
    return (new_s);
}

int count_words(char *s, char marker)
{
    int num_words = 0;
    for (int i = 0; s[i];) {
        for (; s[i] == marker; i++);
        if (s[i] == '\0')
            continue;
        for (; s[i] != marker && s[i]; i++);
        ++num_words;
    }
    return num_words;
}

int tag_i(char *s, char marker, int i)
{
    for (; s[i] != marker && s[i]; i++);
    return i;
}

char **str_to_words(char *s, char marker)
{
    int num_words = count_words(s, marker);
    char **words = malloc(sizeof(char *) * (num_words + 1));
    int j = 0;
    int a = 0;

    for (int i = 0; s[i];) {
        for (; s[i] == marker; i++);
        if (s[i] != '\0' && s[i] != '\n') {
            j = i;
            i = tag_i(s, marker, i);
            words[a] = my_strndup(s, j, i);
        }
        a++;
    }
    words[a] = NULL;
    return (words);
}
