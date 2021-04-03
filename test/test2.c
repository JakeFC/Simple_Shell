#include "tom_shelleck.h"

int main(void)
{
	char *tmp;

	tmp = _getenv("PATH");
	write(STDOUT_FILENO, tmp, _strlen(tmp));
	write(STDOUT_FILENO, "\n", 1);
	free(tmp);
	return (0);
}
