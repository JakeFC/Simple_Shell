#include "tom_shelleck.h"

/**
 * perror_execve - prints an error on execve, given shell and argument names
 * @arg: argument string
 * @shell: name of shell executable
 * @line: line number of command
 * Return: 0
 */
int perror_execve(char *arg, char *shell, int line)
{
	char *tmp1, *tmp2, *str_line;

	tmp1 = str_concat(shell, ": ");
	str_line = _itoa(line);
	tmp2 = str_concat(tmp1, str_line), free(tmp1), free(str_line);
	tmp1 = str_concat(tmp2, ": "), free(tmp2);
	tmp2 = str_concat(tmp1, arg), free(tmp1);
	tmp1 = str_concat(tmp2, ": not found\n"), free(tmp2);
	write(STDERR_FILENO, tmp1, _strlen(tmp1));
	free(tmp1);
	return (0);
}
