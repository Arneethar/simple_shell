#ifndef SHELL_H
#define SHELL_H

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

char *_strdup(char *string);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *path_finder(char *cmd);
int _putchar(char c);
void _puts(char *str);
int _printenv(void);
int _strcmpdir(char *s1, char *s2);
int call_command(char *cmdarr[]);
int strn_cmp(char *s1, char *s2, int i);
char *_getenv(char *var);
void absent(char *cmd);
int _read(char *s, size_t __attribute__((unused))file_stream);

extern char **environ;
#endif
