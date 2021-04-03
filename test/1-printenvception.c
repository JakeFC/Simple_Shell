#include "tom_shelleck.h"

extern char **environ;

/**
 * main - prints the address of env and environ
 * Return: 0
 */
int main(int argc, char **argv, char **env)
{
	printf("env: %p\n", env);
	printf("environ: %p\n", environ);
	return (0);
}
