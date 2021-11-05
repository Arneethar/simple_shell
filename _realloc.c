#include "shell.h"

/**
 * _realloc -  Reallocates a memory block using malloc and free.
 * @ptr: Pointer
 * @old_size: Old size
 * @new_size: New size
 * Return: returns a pointer to the array
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p = ptr;
char *np;
unsigned int i, limit;

if (ptr == NULL)
{
np = malloc(new_size);
if (np == NULL)
return (NULL);

return (np);
}
else if (new_size == 0 && ptr != NULL)
{
free(ptr);
return (NULL);
}
else if (new_size == old_size)
return (ptr);
else if (new_size > old_size || old_size > new_size)
{
if (new_size > old_size)
limit = new_size;
else
limit = old_size;
limit = new_size;
np = malloc(limit);
if (np == NULL)
free(np);
for (i = 0; i < old_size; i++)
{
np[i] = p[i];
}
}
free(ptr);
return (np);
}
