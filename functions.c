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
j = _strlen(dest);
for (i = 0; src[i] != '\0'; i++)
{
dest[j + i] = src[i];
}
dest[j + i] = '\0';
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
int j, i = 0;
while (src[i] != '\0')
{
i++;
}

for (j = 0; j <= i; j++)
{
dest[j] = src[j];
}
dest[j + 1] = '\0';
return (dest);
}

/**
 * _strncmp - string comparison
 * @s1: first string
 * @s2: second string
 * @n: number of strings
 * Return: o if the strings are equal or difference if strings are different
 */
int _strncmp(const char *s1, const char *s2, int n)
{
unsigned char c1 = '\0';
unsigned char c2 = '\0';
int n4;

if (n >= 4)
{
n4 = n >> 2;
do {
c1 = (unsigned char) *s1++;
c2 = (unsigned char) *s2++;
if (c1 == '\0' || c1 != c2)
return (c1 - c2);
c1 = (unsigned char) *s1++;
c2 = (unsigned char) *s2++;
if (c1 == '\0' || c1 != c2)
return (c1 - c2);
c1 = (unsigned char) *s1++;
c2 = (unsigned char) *s2++;
if (c1 == '\0' || c1 != c2)
return (c1 - c2);
c1 = (unsigned char) *s1++;
c2 = (unsigned char) *s2++;
if (c1 == '\0' || c1 != c2)
return (c1 - c2);
} while (--n4 > 0);
n &= 3;
}
while (n > 0)
{
c1 = (unsigned char) *s1++;
c2 = (unsigned char) *s2++;
if (c1 == '\0' || c1 != c2)
return (c1 - c2);
n--;
}
return (c1 - c2);
}


/**
  * _atoi - Change a string to a integer.
  * @s: String.
  * Return: Integer into the string.
  */
int _atoi(char *s)
{
int i = 0, flag = 0, num = 1;
unsigned int potencia = 1, suma = 0;

while (s[i])
{
if ((s[i] == '-' || s[i] == '+') && flag == 0)
{
if (s[i] == '-')
{
num *= -1;
}
else
{
num *= 1;
}
}
else if (s[i] >= '0' && s[i] <= '9')
{
flag = 1;
}
else if (flag)
{
break;
}

i++;
}

i--;
while (s[i] >= '0' && s[i] <= '9')
{
suma += (s[i] - '0') * potencia;
potencia *= 10;
i--;
}

return (suma * num);
}
