#include "shell.h"
/**
 * handle_path - handle the path function
 * @rgv: rgv its an argument
 * @cmd: command enter by the user
 * Return: command to make the execution
 */
char *handle_path(char **rgv, char *cmd)
{
	char *path;

	path = malloc(_strlen("/bin/") + _strlen(cmd) + 1);
	if (!path)
	{
		return (NULL);
	}
	_strcpy(path, "/bin/");

	if (cmd[0] != '/' && cmd[0] != '.')
	{
		rgv[0] = _strcat(path, cmd);
		return (rgv[0]);
	}
	free(path);
	return (cmd);
}
