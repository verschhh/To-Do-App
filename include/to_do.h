/*
** Leonrad Verschuere, 2023
** side_project
** to_do.h
*/

#ifndef TO_DO_H_
#define TO_DO_H_

int print_list(char *filename);
int add_task(char *filename, char *task);
int init_del_task(char *filename, char *task);
char **str_to_words(char *s, char marker);
int count_words(char *s, char marker);
char *my_strndup(char *s, int beginning, int end);

#endif /* !TO_DO_H_ */