#include "shell.h"
/**
 * _printenv - prints environment like printenv
 *
 * Return: 0
 */
int _printenv(void)
{
char *s = environ[0];
int i = 0;

while (s)
{
write(1, s, _strlen(s));
write(1, "\n", 1);
s = environ[++i];
}
return (0);
}

/**
 * strn_cmp - lexicographically compares not more that a selected number of
 * characters from two strings
 * @s1: string 1
 * @s2: string 2
 * @i: number determinant
 * Return: 1 for s2 > s1, 0 for equal and and 1 for s1 > s2
 */

int strn_cmp(char *s1, char *s2, int i)
{
  char p1, p2;
  while (i--)
    {
      p1 = *s1++;
      p2 = *s2++;
      if (p1 == '\0' || p1 != p2)
	return (p1 > p2 ? 1 : (p1 < p2 ? -1 : 0));
    }
  return (0);
}

/**
 * _getenv - prints environment similar to getenv
 * @var: environ variable
 * Return: 0
 */
char *_getenv(char *var)
{
int i = 0;

for (i = 0; environ[i]; i++)
{
if (strn_cmp(environ[i], var, _strlen(var)) == 0)
return (&environ[i][_strlen(var)]);
}
return (NULL);
}
