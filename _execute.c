#include "shell.h"


/**
 * _disp_cnf_err - it displays error for command not found.
 * @pn: program name that from which generated the error.
 * @err_src: error source to print.
 * @num: typed commands number.
 * Return: nothing.
 */
void _disp_cnf_err(char *pn, char *err_src, int num)
{
_puts(pn);
_puts(": ");
_putchar(num + '0');
_puts(": ");
_puts(err_src);
_puts(": not found");
}

/**
 * _disp_err - it displays normal errors.
 * @cmd: command.
 * Return: nothing.
 */
void _disp_err(char *cmd)
{
perror(cmd);
}


/**
 * exec_usr_input - execute user input in shell.
 * @av0: first element of av.
 * @cmds: typed commands.
 * @status: number to change it's value with sys call wait.
 * @lineptr: getline's buffer;
 * Return: void.
 */
void exec_usr_input(char *av0, char **cmds, int status, char *lineptr)
{
pid_t c;

c = fork();
if (c == -1)
{
perror(av0);
}
if (c == 0)
{
if (execve(cmds[0], cmds, environ) == -1)
{
perror(av0);
exit(EXIT_FAILURE);
}
}
if (wait(&status) == -1)
{
_free_proc_conds(cmds, lineptr);
perror(av0);
}
}
