#include "tom_shelleck.h"

int main(void)
{
	size_t len = 1024;
	char *buf = malloc(sizeof(char) * len);

	if (!buf)
		return (1);
	printf("$ ");
	if (getline(&buf, &len, stdin) != -1)
		fprintf(stdout, "%s", buf);
	free(buf);
	return (0);
}
