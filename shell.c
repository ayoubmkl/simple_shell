#include "shell.h"
/**
 * main - main function
 * @arc: len its an argument
 * @arv: arv its an argument by user
 * @envp: envp argument env
 * Return: 0
 */
int main(int arc, char **arv, char **envp)
{
	bool interactive = (arc == 1 && isatty(STDIN_FILENO));

	prompt(arv, envp, interactive);
	return (0);
}
