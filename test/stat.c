#include "tom_shelleck.h"

/**
 * main - stat example
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	unsigned int i, ii, bi;
	struct stat st;
	char *buf = malloc(sizeof(char) * 1024);
	int size = 1024;

	if (ac < 2)
	{
		printf("Usage: %s file_name ...\n", av[0]);
		return (1);
	}
	while (getcwd(buf, size) == NULL)
	{
		size *= 2;
		free(buf);
		buf = malloc(sizeof(char) * size);
	}
	bi = _strlen(buf);
	for (i = 1; av[i]; i++, bi = _strlen(buf))
	{
		for (ii = 0; av[i][ii]; ii++)
			buf[bi] = av[i][ii];
		buf[bi] = 00;
		printf("%s:", av[i]);
		if (stat(av[i], &st) == 0)
		{
			printf(" FOUND\n");
		}
		else
		{
			printf(" NOT FOUND\n");
		}
	}
	free(buf);
	return (0);
}
