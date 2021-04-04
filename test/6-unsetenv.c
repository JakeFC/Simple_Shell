#include "tom_shelleck.h"

extern char **environ;

/**
 * _unsetenv deletes a variable name from the environment
 * @name: name of env variable
 * Return: always 0
 */
int _unsetenv(const char *name)
{
	int i;

	i = env_index(name);
	if (i < 0)
		return (0);
	for (; environ[i]; i++)
		environ[i] = environ[i + 1];
	return (0);
}
