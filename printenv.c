#include "tom_shelleck.h"

/**
 * _printenv - prints the environment using environ
 * Return: always 3
 */
int _printenv(void)
{
	int i = 0;

	if (!environ)
		return (3);
	if (!environ[i])
		return (3);
	for (; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (3);
}
