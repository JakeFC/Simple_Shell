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
	int size = 1024, len;

	if (ac < 2)
	{
		printf("Usage: %s file_name ...\n", av[0]);
		return (1);
	}
/* put working directory in buffer & while buf is too small, free and */
/*  allocate double before doing it again */
	while (getcwd(buf, size) == NULL)
	{
		size *= 2;
		free(buf);
		buf = malloc(sizeof(char) * size);
	}
/* start buffer index at end of directory name */
	bi = _strlen(buf);
	buf[bi++] = '/';
	for (len = bi, i = 1; av[i]; i++, bi = len)
	{
/* write the arguments into the buffer to get full path */
		for (ii = 0; av[i][ii]; ii++, bi++)
			buf[bi] = av[i][ii];
		buf[bi] = 00;
		printf("%s\n", buf);
		printf("%s:", av[i]);
		if (stat(buf, &st) == 0)
			printf(" FOUND\n");
		else
			printf(" NOT FOUND\n");
	}
	free(buf);
	return (0);
}
