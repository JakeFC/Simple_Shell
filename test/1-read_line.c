#include "tom_shelleck.h"

int main(void)
{
	size_t len = 1024, writelen;
	char *buf = malloc(sizeof(char) * len);
	ssize_t getlen;

	if (!buf)
		return (1);
	printf("$ ");
	if ((getlen = getline(&buf, &len, stdin)) != -1)
	{
		writelen = getlen;
		write(STDOUT_FILENO, buf, writelen);
	}
	free(buf);
	return (0);
}
