#include "shell.h"
/**
 * path_finder - Takes PATH string, tokenizes it, then concats with "/" & cmd
 * @cmd: command passed from getline in main
 * Return: new_path
 */

char *path_finder(char *cmd)
{

  int i = 0, j = 0;
  char *path = _strdup(_getenv("PATH"));
  char *path_tokens = path_tokens = strtok(path, ":");
  char *path_array[100];
  char *string = cmd;
  char *new_path = NULL;
  struct stat buffer;

  
  new_path = malloc(sizeof(char) * 100);
  if (_getenv("PATH")[0] == ':')
		if (stat(cmd, &buffer) == 0)
			return (_strdup(cmd));
  
  /* tokenise to get each path since its seperated by : */
 

  while (path_tokens != NULL)
    {
      /* store each path in path_array */
      path_array[i++] = path_tokens;
      path_tokens = strtok(NULL, ":");
    }
  path_array[i] = NULL;
  /* appending / to path and adding command */
  for (j = 0; path_array[j]; j++)
    {
      _strcpy(new_path, path_array[j]);
      _strcat(new_path, "/");
	_strcat(new_path, string);
      _strcat(new_path, "\0");

      if (stat(new_path, &buffer) == 0)
	{
	  free(path);
	  return (new_path);
	}
      else
	new_path[0] = 0;
    }
  free(path);
  free(new_path);

  if (stat(cmd, &buffer) == 0)
    return (_strdup(cmd));
  return (NULL);
}
