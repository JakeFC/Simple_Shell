#include "tom_shelleck.h"

/**
 * builtin_checker - checks whether builtin functions were called
 * @args: array of argument tokens
 * @shell: name of shell executable
 * @line: line number of command
 * @errcode: address of errorcode int
 * Return: 0 if not called, 1 if called without argument, 2 if called with arg,
 * or 3 if a builtin was called with error or an empty string/array was passed
 */
int builtin_checker(char **args, char *shell, int line, int *errcode)
{
	int i;

	if (!args)
		return (3);
	if (!args[0])
		return (3);
	if (_strcmp(args[0], "setenv") == 0)
	{
		if (!args[1] || !args[2] || _setenv(args[1], args[2]) == -1)
			*errcode = 2, perror("setenv");
		return (3);
	}
	if (_strcmp(args[0], "unsetenv") == 0)
	{
		if (!args[1] || _unsetenv(args[1]) == -1)
			perror("unsetenv");
		return (3);
	}
	if (_strcmp(args[0], "exit"))
		return (0);
	if (!args[1])
		return (1);
	for (i = 0; args[1][i]; i++)
		if (args[1][i] < 48 || args[1][i] > 57 || i > 9)
		{
			perror_exit(args[1], shell, line);
			*errcode = 2;
			return (3);
		}
	if (_atoli(args[1]) > INT_MAX)
	{
		perror_exit(args[1], shell, line);
		*errcode = 2;
		return (3);
	}
	return (2);
}
/**
 * perror_exit - prints an exit error with given argument and shell names
 * @arg: argument string
 * @shell: shell executable name
 * @line: line number of command
 * Return: 0
 */
int perror_exit(char *arg, char *shell, int line)
{
	char *tmp1, *tmp2, *str_line;

	tmp1 = str_concat(shell, ": ");
	str_line = _itoa(line);
	tmp2 = str_concat(tmp1, str_line), free(tmp1), free(str_line);
	tmp1 = str_concat(tmp2, ": exit: Illegal number: "), free(tmp2);
	tmp2 = str_concat(tmp1, arg), free(tmp1);
	tmp1 = str_concat(tmp2, "\n"), free(tmp2);
	write(STDERR_FILENO, tmp1, _strlen(tmp1));
	free(tmp1);
	return (0);
}
