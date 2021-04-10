#include "tom_shelleck.h"

/**
 * exit_checker - checks whether exit function was called
 * @args: array of argument tokens
 * @shell: name of shell executable
 * Return: 0 if not called, 1 if called correctly, 2 if called with error
 */
int exit_checker(char **args, char *shell)
{
	int i;

	if (_strcmp(args[0], "exit"))
		return (0);
	if (!args[1])
		return (1);
	for (i = 0; args[1][i]; i++)
		if (args[1][i] < 48 || args[1][i] > 57)
		{
			pexit_error(args[1], shell);
			return (2);
		}
	return (1);
}
/**
 * pexit_error - prints an exit error with given argument and shell names
 * @arg: argument string
 * @shell: shell executable name
 */
void pexit_error(char *arg, char *shell)
{
	char *tmp1, *tmp2;

	tmp1 = str_concat(shell, ": 1: exit: Illegal number: ");
	tmp2 = str_concat(tmp1, arg), free(tmp1);
	tmp1 = str_concat(tmp2, "\n"), free(tmp2);
	write(STDERR_FILENO, tmp1, _strlen(tmp1));
	free(tmp1);
}
