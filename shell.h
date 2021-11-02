#ifndef SHELL_H
#define SHELL_H

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_uitoa(unsigned int count);


void print_prompt1(void);
void print_prompt2(void);

char *read_cmd(void);

#endif
