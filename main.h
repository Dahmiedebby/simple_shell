#ifndef MAIN_H_
#define MAIN_H_
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>

char *argstostr(int ac, char **av);
char *_getenv(const char *name);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char **strtow(char *str, char delimeter);
char *_strcat(char *dest, char *src);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
char *_strdup(char *str);
void free_grid(char **grid);
char *_find_command(char *command, char **path);
int _stat(char *command);
void getline_error(char *_st, char *line, char **tab, char **path);
void free_memory(char *tmp, char *_st, char *line, char **tab);
void print_env(void);
void builtin_command(char *ln, char *tmp, char **pth,
char **tab, char **av, int *fg, int *st, int i);
void execute(char *command, char **argv);
void write_error(char *filename);
void write_not_found_error(char *av, int i, char *cmd, int *status);
void write_illegal_error(char *av, char *cmd, int i);
int _setenv(const char *variable, const char *value, int overwrite);
int _strc(const char *str, char ch);
char *_strcpy(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strncpy(char *dest, char *src, int n);
void shell_prompt(size_t *buffer_size, size_t *i);
int  get_line_tester(int numberchar, int status, char *line,
char **tmp, char **path);
size_t _getline(char **line, size_t *buffer_size, size_t fd);
void child(int *status, int *fg, char *cmd, char *ln, char **tab, char **path);
void free_path(char **grid);
extern char **environ;
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _atoi(char *str);

#endif
