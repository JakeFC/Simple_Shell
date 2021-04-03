#include "tom_shelleck.h"
extern char **environ;
/**
 * main - prints the environment using environ
 * Return: always 0
 */
int main(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
