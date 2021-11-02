#include "shell.h"

char *name;
/**
 * main - handling prompt, EOF and read file_stream
 * @argc: To be declare void
 * @argv: needed for the command
 * Return: Always 0
 */
int main(int argc, char **argv)
{
    char *line = NULL;
    size_t buffer_size = 0;
    ssize_t file_stream = 0;

    (void) argc;
    name = argv[0];

    while(1)
      
    {
      if (isatty(STDIN_FILENO) == 1)
	_puts("$ ");
      /* getline can dynamically reallocates space for string */
      file_stream = getline(&line, &buffer_size, stdin);
      if (file_stream == -1) /* if an error occur or EOF reached*/
	{

	  if (isatty(STDIN_FILENO) == 1)
	    write(1, "\n", 1);
	  break;
	}

      if (line[file_stream - 1] == '\n')
	line[file_stream - 1] = '\0';

      if (*line == '\0')
	continue;
      if (_read(line, file_stream) == 2)
	break;
    }
    free(line);
    line = NULL;
    return (0);
}


/**
 * _read - function to parse the input
 * @s: string
 * @file_stream: getline inputs
 * Return: 0;
 */
int _read(char *s, size_t __attribute__((unused))file_stream)
{
  char *token = NULL;
  char *cmdarr[100];
  int i = 0;
  char *delim;

  if (_strcmp(s, "exit") == 0)
    return (2);
  if (_strcmp(s, "env") == 0)
    return (_printenv());
  token = strtok(s, delim);

  while(token)
    {
      cmdarr[i++] = token
	token = strtok(NULL, delim);
    }
  cmd arr[i] = NULL;

  return (call_command(cmd_arr));
}

/**
 * absent - print in the absence of command in path
 * @cmd: a string from stdin
 */
void absent(char *cmd)
{
write(2, name, _strlen(name));
write(2, ": 1:", 5);
write(2, cmd, _strlen(cmd));
write(2, ": not found\n", 12);
}

/**
 * call_command - calls cmd, forks, execve
 *
 * @cmdarr: a string provided by stdin
 * Return: 0;
 */

int call_command(char *cmdarr[])
{
  char *exe_path_str = NULL;
	char *cmd = NULL;
	pid_t is_child;
	int status;

	cmd = cmdarr[0];
	exe_path_str = pathfinder(cmd);
	if (exe_path_str == NULL)
	{
		print_not_found(cmd);
		return (3);
	}
	is_child = fork();
	if (is_child < 0)
	{
		perror("Error:");
		return (-1);
	}
	if (is_child > 0)
		wait(&status);
	else if (is_child == 0)
	{
		(execve(exe_path_str, cmdarr, environ));
		perror("Error:");
		exit(1);
	}
	free(exe_path_str);
	return (0);
}
