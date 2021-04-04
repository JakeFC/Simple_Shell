#include "tom_shelleck.h"
extern char **environ;
/**
 * main - prints the environment using environ
 * Return: always 0
 */
int main(void)
{
	int i;

	if (_setenv("NEW_VAR", "new_value", 0) == -1)
		return (1);
	_unsetenv("PWD");
	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free(environ[i - 1]);
	free(environ);
	return (0);
}
