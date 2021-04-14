#include "tom_shelleck.h"

/**
 * main - runs a command line interpreter
 * @argc: argument count
 * @argv: array of argument strings
 * Return: 0 on success, or the error code provided by _getline
 * Description: this function's only purpose is to send the correct executable
 * name to the rest of the code for error handling
 */
int main(int argc, char **argv)
{
	(void)argc;
	signal(SIGINT, _handler);
	environ = malloc_array(environ);
	return (_getline(argv[0]));
}
/**
 * _handler - prints a new prompt on a newline
 * @sig: ignored input
 */
void _handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}
