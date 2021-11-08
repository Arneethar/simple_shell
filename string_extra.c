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
