#include "shell.h"
/**
 *sig_handler - handler control
 * @num: number of the argument
 */
void sig_handler(int num)
{
	(void)num;
	write(STDOUT_FILENO, "\n$ ", _strlen("\n$ "));
}
/**
 *prompt - a shell
 *@arv: argument made by users
 *@envp: environement variable argument
 *@flg: flag argument
 */
void prompt(char **arv, char **envp, bool flg)
{
	size_t n = 0;
	ssize_t num_c = 0;
	char *cmd = NULL, *rgv[MAX_C];
	int x/*, stat,path*/;

	while (1)
	{
		if (flg && isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", _strlen("$ "));
		signal(SIGINT, sig_handler);
		num_c = getline(&cmd, &n, stdin);
		if (num_c == -1) /*handles the end file case*/
		{
			free(cmd);
			exit(EXIT_SUCCESS);
		}
		if (cmd[num_c - 1] == '\n')
			cmd[num_c - 1] = '\0';
		cmd = trim(cmd);
		if (_strlen(cmd) == 0)
			continue;
		x = 0;
		rgv[x] = strtok(cmd, " \n");
		handle_exit(cmd);
		handle_path(rgv, cmd);
		while (rgv[x])
		{
			x++;
			rgv[x] = strtok(NULL, " \n");
		}
		runcmd(rgv, arv, envp); /* envir */
	}
	free(cmd);
}
