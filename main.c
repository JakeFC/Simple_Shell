#include "tom_shelleck.h"

/**
 * simple_shell - runs a command line interpreter
 * @argc: argument count
 * @argv: array of argument strings
 * Return: 0 on success, or 1 on error
 * Description: this function's only purpose is to send the correct executable
 * name to the rest of the code for error handling
 */
int main(int argc, char **argv)
{
	(void)argc;
	return (_getline(argv[0]));
}