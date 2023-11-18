#include "shell.h"
/**
 * handle_exit - Function finish  the program when
 * user types "quit".
 * @cmd: the string to be readed
 * Return: nothing
 *
 */
void handle_exit(char *cmd)
{
	if (_strcmp("exit", cmd) == 0)
	{
		free(cmd);
		exit(EXIT_SUCCESS);
	}
}
