#include "shell.h"

/**
  * _cd - Change the directory.
  * @args: List of arguments passed from parsing.
  * @input: Input line for free.
  * Return: 1 if works.
  */
int _cd(char **args, __attribute__((unused)) char *input)
{

if (args[1] == NULL)
{
if (chdir(_getenv("HOME")) != 0)
{
perror("hsh:");
}
}
else
{
if (chdir(args[1]) != 0)
{
perror("hsh:");
}
}
return (1);
}


/**
  * _help - Display the help for a command.
  * @args: List of arguments passed from parsing.
  * @input: Input line for free.
  * Return: 1 if works.
  */
int _help(__attribute__((unused)) char **args,
		__attribute__((unused)) char *input)
{
int i;
char *builtin_str[] = {"cd", "help", "exit"};

for (i = 0; i < 3; i++)
{
write(STDOUT_FILENO, builtin_str[i], _strlen(builtin_str[i]));
write(STDOUT_FILENO, "\n", 1);
}
return (1);
}

/**
 * exit_func - exit function
 * @cmds: commands array.
 * Return: void.
 */
void exit_func(char **cmds)
{
int i;

if (!cmds[1])
exit(0);
else
{
i = _atoi(cmds[1]);
if (i < 0)
i = 2;

exit(i);
}
}
/**
  * _env - Display the environ in the shell.
  * @args: List of arguments passed from parsing.
  * @input: Input line for free.
  * Return: 1 if works.
  */
int _env(__attribute__((unused)) char **args,
		__attribute__((unused)) char *input)
{
int i = 0;

while (environ[i] != 0)
{


_puts(environ[i]);
_puts("\n");
i++;
}
return (1);
}

/**
  * _setenv - Set an environment variable.
  * @name:Name of the variable
  * @value: Value in the variable.
  * Return: 1 if works.
  */
int _setenv(char *name, char *value)
{
char *tmp, new_variable[1024];
char **ep = environ;
char **ev;
int counter = 0, i;

if (value == NULL)
{
perror("hsh:");
}
tmp = _getenv(name);
if (tmp != NULL)
{
_strcpy(tmp, value);
}
else
{
while (ep[counter] != NULL)
{
counter++;
}
counter += 2;
ev = malloc(counter * sizeof(char *));
for (i = 0; ep[i] != NULL; i++)
{
ev[i] = ep[i];
}
_strcat(new_variable, name);
_strcat(new_variable, "=");
_strcat(new_variable, value);
ev[i] = new_variable;
ev[++i] = NULL;
environ = ev;
free(ep);
}

return (1);
}
