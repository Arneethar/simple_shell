#include "shell.h"
/**
 * _strdup - function pointer to a memory which an input string is copied
 *  @str: input string
 * Return: *pointer to the copied string
 */
char *_strdup(char *str)
{
unsigned int i = 0, len = 0;
char *p;

if (str == NULL)
return (NULL);

while (str[len])
{
len++;
}

p = malloc(sizeof(char) * (len + 1));

if (p == NULL)
return (NULL);

while ((p[i] = str[i]) != '\0')
i++;
return (p);
}

/**
 * _strlen - function to count number of characters in a string
 * @str: string to be counted
 * Return: counter
 */
int _strlen(char *str)
{
int i = 0;
for (i = 0; str[i] != '\0'; i++)
{
;
}
return (i);
}


/**
 * _strcmp - compare strings
 * @s1: string
 * @s2: string
 * Return: 0 if strings are equal, non-zero, otherwise.
 */
int _strcmp(char *s1, char *s2)
{
int s1len = 0;
int s2len = 0;
int len = 0;
int i;

s1len = strlen(s1);
s2len = strlen(s2);

if (s2len >= s1len)
len = s1len;
else
len = s2len;
for (i = 0; i < len; i++)
{
if (s2[i] != s1[i])
{
return (s1[i] - s2[i]);
}
}
return (0);
}


