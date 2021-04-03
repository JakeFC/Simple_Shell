#include "tom_shelleck.h"

/**
 * main - runs ls -l /tmp 5 times
 * Return: 0
 */
int main(void)
{
	int child, status, waitv, i;
	char *args[] = {"/bin/ls", "-la", "/tmp", NULL};

	for (i = 0; i < 5; i++)
	{
		child = fork();
/* if we're in the child process */
		if (child == 0)
/* run arguments and print error msg on error */
			if (execve(args[0], args, NULL) == -1)
				perror("Ececve");
/* make parent wait for child to exit and check for error before continuing */
		if ((waitv = waitpid(child, &status, 0)) == -1)
			perror("Wait");
	}
	return (0);
}
