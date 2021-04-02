#include "tom_shelleck.h"

int main(int argc, char **argv)
{
	(void)argc;

	for (; *argv; *argv++)
		printf("%s\n", *argv);
	return (0);
}
