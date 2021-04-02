#include "tom_shelleck.h"

int main(void)
{
	pid_t parent;

	parent = getppid();
	printf("parent: %u\n", parent);
	return (0);
}
