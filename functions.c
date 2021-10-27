#include "main.h"
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
