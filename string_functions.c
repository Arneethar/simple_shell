#include "shell.h"
/**
 * _strlen - Find the lenght of a string.
 * @s: string.
 * Return: lenght of the string.
 */
int _strlen(char *s)
{
int i = 0;

while (*(s + i) != '\0')
{
i++;
}
return (i);
}

/**
 * _strcat - Concatent two strings.
 * @dest: string.
 * @src: string.
 *
 * Return: Strings concated.
 */
char *_strcat(char *dest, char *src)
{
int i;
int size = _strlen(dest);

for (i = 0; src[i] != '\0'; i++)
{
dest[size + i] = src[i];
}
dest[size + i] = '\0';

return (dest);
}

/**
 * _strcmp - compare strings
 * @s1: string
 * @s2: string
 * Return: 0 if strings are equal, non-zero, otherwise.
 */
int _strcmp(const char *s1, const char *s2)
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

/**
  * _strcpy - Print the same string.
  * @dest: array;
  * @src: string;.
  *
  * Return: The string copiedi.
  */
char *_strcpy(char *dest, char *src)
{
int j, i = 0;

while (*(src + i) != '\0')
{
i++;
}

for (j = 0; j <= i; j++)
{
*(dest + j) = *(src + j);
}

dest[j + 1] = '\0';
return (dest);
}

/**
  * _strncmp - String comaprison.
  * @s1: string 1
  * @s2: string 2
  * @n: number of bytes
  * Return: 0 if equal diff if different.
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
 * _strdup - returns a pointer to a newly allocated memory space, which contai
 * a copy of the string given a s a parameter
 * @str: string
 * Return: str or NULL
 */
char *_strdup(char *str)
{
int len = 0;
char *p;
int i;

if (str == NULL)
return (NULL);

 while (str[len])
len++;
p = malloc(sizeof(char) * len + 1);
if (p == NULL)
{
return (NULL);
}
for (i = 0; i <= len; i++)
p[i] = str[i];
return (p);
}

/**
 * _const_strconcat - concatenates s2 to the end of s1.
 * @s1: string 1.
 * @s2: string 2.
 * Return: pointer to char of the new concatenated string.
 */
char *_const_strconcat(const char *s1, const char *s2)
{
int len1 = 0, len2 = 0, lens_sum, i;
char *str;

while (s1[len1] != '\0')
len1++;
while (s2[len2] != '\0')
len2++;

lens_sum = len1 + len2;
str = malloc(sizeof(char) * (lens_sum + 1));

if (str == NULL)
return (NULL);

for (i = 0; i < lens_sum; i++)
{
if (i < len1)
str[i] = s1[i];
else
str[i] = s2[i - len1];
}
str[lens_sum] = '\0';
return (str);
}
