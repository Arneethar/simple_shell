#include "shell.h"
/**
 * _strcmpdir - compares strings to find dir
 * @s1: first string
 * @s2: second string
 * Return: if match
 */
int _strcmpdir(char *s1, char *s2)
{
int i = 0;

for (; (*s2 != '\0' && *s1 != '\0') && *s1 == *s2; s1++)
{
if (i == 3)
break;
i++;
s2++;
}

return (*s1 - *s2);
}



/**
 * _putchar - function that outputs a character
 * @c: input character
 * Return: input as output
 */
int _putchar(char c)
{
return(write(1, &c, 1));
}

/**
 * _strlen - function to print the length of a string in c
 * @str: string to be counted
 * Return: length of string
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
 * _strcat - function that concatenates two strings
 *
 * @dest: pointer to destination char
 * @src: pointer to source char
 * Return: Always (Dest)
 */
char *_strcat(char *dest, char *src)
{
int i, j;
for (i = 0; src[i] != '\0'; i++)
{
for (j = 0; dest[j] != '\0'; j++)
{
;
}
dest[j] = dest[j] + src[i];
}
return (dest);
}

/**
 * _puts - a function to write a string to std out
 * @str:pointer pointing to the string characters
 * Return: Always str (success)
 */

void _puts(char *str)
{
int i = 0;
while (str[i] != '\0')
{
_putchar(str[i]);
i++;
}
}

/**
 * _strdup - copies the input string
 * @string: input string
 *
 * Return: *ptr to the copied string or  NULL (if Error)
 */
char *_strdup(char *string)
{
char *dup;
unsigned int i = 0, length = 0;

if (string == NULL)
return (NULL);

while (string[length])
length++;

dup = malloc(sizeof(char) * (length + 1));

if (dup == NULL)
return (NULL);

while ((dup[i] = string[i]) != '\0')
i++;

return (dup);
}
/**
 * _strcmp - Compare two strings
 * @s1: string
 * @s2: string
 * Return: negative int if s1 < s2, 0 if matching, and positive int if s1 > s2
 */
int _strcmp(char *s1, char *s2)
{
int i;

for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
{
if (s1[i] != s2[i])
return (s1[i] - s2[i]);
}
return (0);
}
/**
 *_strcpy - prints n elements of an array of integers
 *@dest: input
 *@src: input
 *Return: dest
 */
char *_strcpy(char *dest, char *src)
{
char *r = dest;

while (*src != '\0')
{
*dest = *src;
src++;
dest++;
}
*dest = '\0';
return (r);
}
