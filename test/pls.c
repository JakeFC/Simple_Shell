#include "tom_shelleck.h"

int main(void)
{
	int i;

	environ = malloc_array(environ);
	for (i = 0; environ[i]; i++)
	{
		puts(environ[i]);
		free(environ[i]);
	}
	free(environ);
	return (0);
}
