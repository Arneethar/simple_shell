#include "shell.h"

/**
  * sig_handler - Signal handler.
  * @sig: signal.
  */

void sig_handler(int sig)
{
(void)sig;
_puts("\n$ ");

}
