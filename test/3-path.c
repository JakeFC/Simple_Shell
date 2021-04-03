#include "tom_shelleck.h"

int main(void)
{
	int i;
	char **arr = strtok_array_test(_getenv("PATH"), ":");

	if (!arr)
		return (1);
	for (i = 0; arr[i]; i++)
	{
		write(STDOUT_FILENO, arr[i], _strlen(arr[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
	return (0);
}
