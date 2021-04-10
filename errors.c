#include "tom_shelleck.h"

/**
 * perror_execve - prints an error on execve, given shell and argument names
 * @arg: argument string
 * @shell: name of shell executable
 * Return: 0
 */
int perror_execve(char *arg, char *shell)
{
	char *tmp1, *tmp2;

	tmp1 = str_concat(shell, ": 1: ");
	tmp2 = str_concat(tmp1, arg), free(tmp1);
	tmp1 = str_concat(tmp2, ": not found\n"), free(tmp2);
	write(STDERR_FILENO, tmp1, _strlen(tmp1));
	free(tmp1);
	return (0);
}
