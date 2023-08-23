#ifndef SHELL_H
#define SHELL_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <ctype.h>
#include <malloc.h>
#include <signal.h>
#include <dirent.h>
#include <errno.h>

extern char **environ;
#define BUFFSIZE 1024
#include "sh_macros.h"

/************** STRUCTURES ****************/

/**
 * struct shl_data - this stores all shell data
 * @av: argument vector
 * @args: argument vector
 * @env: environnement list
 * @lin: pointer to the input read from _getline
 * @fd: file descriptor to the input commands
 * @toks: pointer to the array of parsed inputs
 * @ls_alias: array of pointers with aliases
 * @counter: counts the number of executed command
 */
typedef struct shl_data
{
	char *av;
	char *args;
	char **env;
	char *lin;
	int fd;
	int counter;
	char **ls_alias;
	char **toks;
} dat_t;

/**
 * struct builtin - this handles builtin command
 * @nam: command name
 * @funt: pointer to the function associated
 */

typedef struct builtin
{
	char *nam;
	int (*funt)(dat_t *data);
} bn_t;


/******************* Built-in functions ************/
int bn_cd(dat_t *data);
int bn_env(dat_t *data);
int bn_exit(dat_t *data);
int bn_setenv(dat_t *data);
int bn_unsetenv(dat_t *data);
/* If there is a match builtin, execute it */
int bn_list(dat_t *data);
/* set the work directory */
int _setdir(dat_t *data, char *nw_dir);
/* shows help info */
int bn_help(dat_t *data);
/* this sets, unsets and shows alias */
int bn_alias(dat_t *data);


/*********** sh_get_cmd_path.c **************/
/* Creates an array of the path dirs */
char **parse_path(dat_t *data);

/* this searches for program in the path */
int search_prog(dat_t *data);


/*************_getenv.c ***************/

/* Gets the value of an environment variable */
char *_envpath(char *name, dat_t *data);

/* Overwrite the value of the environment variable */
int _envsetpath(char *path, char *val, dat_t *data);

/* Remove a key from the environment */
int _envrempath(char *path, dat_t *data);

/* prints the current environ */
void _printenv(dat_t *data);


/************** shell.c *****************/

/* Init the struct with the data of the program */
void init_data(dat_t *data, int arc, char *argv[], char **env);

/* Makes the infinite loop that shows the prompt*/
void uche(char *prompt, dat_t *data);

/* Print the prompt in a new line */
void sh_ctrl_c(int opr UNUSED);


/********* string functions ************/
char *_strcat(char *s1, char *s2);
char *_strtok(char *line, char *del);
void tokenize(dat_t *data);
int _atoi(char *s);
int _strncmp(char *s1, char *s2, int n);
void _strrev(char *str);
char *_strcpy(char *des, char *src);
int _strlen(char *s);
char *_strdup(char *str);
int sh_print(char *str);
/* Cast from int to string */
void _itoa(long num, char *str, int base);
/* count the coincidences of character in string */
int _countchars(char *str, char *chars);


/********* shell_alias.c **************/

/* prints list of alias */
int _printalias(dat_t *data, char *alias);

/* gets alias name */
char *_getalias(dat_t *data, char *name);

/* sets alias name */
int _setalias(char *alias_name, dat_t *data);

/* expand aliases */
void _expalias(dat_t *data);

/* add the string at the end of the buffer*/
int buffer_add(char *buffer, char *str_add);

/* expand variables */
void _expvar(dat_t *data);

/* Frees the memory for directories */
void free_ptr_array(char **dirs);

/* Free the fields needed each loop */
void free_data(dat_t *data);

/* Free all field of the data */
void freemor_data(dat_t *data);


/* line functions */
/* Read one line of the standar input*/
int _getline(dat_t *data);

/* split the each line for the logical operators if it exist */
int _chcklogops(char *arrcmds[], int i, char arrops[]);

/* Execute a command with its entire path */
int _execute(dat_t *data);

/* Prints a string in the standar error */
int sh_printerror(int errorcode, dat_t *data);
/* Prints a string in the standar error */
int she_print(char *str);

#endif
