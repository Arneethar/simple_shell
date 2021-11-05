#ifndef _SHELL_H_
#define _SHELL_H_

/* Required libraries */
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>

/* Environmental variables */

extern char **environ;

typedef struct dir
{
char *directory_path;
struct dir *next;
} dir;
/* Function declarations (prototypes) for main functions*/


int _setenv(const char *name, const char *value, int overwrite);
char *_getenv(const char *name);
int _unsetenv(const char *name);

int _strlen(char *s);
int _strcmp(const char *s1, const char *s2);
char *_const_strconcat(const char *s1, const char *s2);
char *_strconcat(char *s1, char *s2);
char *_strdup(char *str);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

int _get_cmds_number(char *str);
void _free_cmds(char **cmds);

int _putchar(char c);
void _puts(char *str);

char *_find_path(char *str);

void _disp_cnf_err(char *pn, char *err_src, int num);
void _disp_err(char *str);

char **create_cmds(char *str);

void sig_handler(int i);

void exec_usr_input(char *av0, char **cmds, int status, char *lineptr);

void _free_proc_conds(char **cmds, char *lineptr);

int _atoi(char *str);

void exit_func(char **cmds);
#endif
