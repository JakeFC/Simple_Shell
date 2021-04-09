#include "tom_shelleck.h"
/**
 * cmd_cwd - appends the cmd string to the current directory if found there
 * @cmd: first string of command
 * Return: string starting with cwd and ending with the cmd if found there,
 * else NULL
 */
char *cmd_cwd(char *cmd)
{
	unsigned int i, bi, size = 120;
	struct stat st;
	char *buf = malloc(sizeof(char) * size);

	if (!cmd || !buf)
		return (NULL);
/* put working directory in buffer & while buf is too small, free and */
/*  allocate double before doing it again */
	while (getcwd(buf, size) == NULL)
	{
		size *= 2, free(buf);
		buf = malloc(sizeof(char) * size);
		if (!buf)
			return (NULL);
	}
/* start buffer index at end of directory name */
	bi = _strlen(buf);
	buf[bi++] = '/';
/* write the arguments into the buffer to get full path */
	for (i = 0; cmd[i]; i++, bi++)
	{
		if (bi + 1 > size)
		{
/* reallocate if buf is too small to add cmd */
			buf = _reallocf(buf, size, size * 2), size *= 2;
			if (!buf)
				return (NULL);
		}
		buf[bi] = cmd[i];
	}
	buf[bi] = 00;
	if (stat(buf, &st) == 0)
		return (buf);
	free(buf);
	return (NULL);
}
/**
 * cmd_path - appends the cmd string to the given path directory if found there
 * @cmd: first string of command
 * @path: single path directory string to test
 * Return: string starting with path and ending with the cmd if found there,
 * else NULL
 */
char *cmd_path(char *cmd, char *path)
{
	unsigned int i, bi;
	struct stat st;
	char *buf;

	if (!cmd || !path)
		return (NULL);
/*  allocate buffer for both strings, plus NULL byte and '/' char */
	buf = malloc(sizeof(char) * (_strlen(cmd) + _strlen(path) + 2));
	if (!buf)
		return (NULL);
/* put path directory into buffer */
	for (bi = 0; path[bi]; bi++)
		buf[bi] = path[bi];
/* start buffer index at end of directory name, replacing NULL byte with '/' */
	buf[bi++] = '/';
/* write the arguments into the buffer to get full path */
	for (i = 0; cmd[i]; i++, bi++)
		buf[bi] = cmd[i];
	buf[bi] = 00;
	if (stat(buf, &st) == 0)
		return (buf);
	free(buf);
	return (NULL);
}
/**
 * slash_specified - checks whether the argument contains a '/' character
 * @str: string being checked
 * Return: number of '/' characters found, or 0 for none
 */
int slash_specified(char *str)
{
	int i, count = 0;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
		if (str[i] == '/')
			count++;
	return (count);
}
/**
 * empty_path_check - checks the path value for an empty field
 * @path: path value string
 * Return: future token index before which current directory should be checked,
 * or -1 if none found
 */
int empty_path_check(char *path)
{
	int i, index = 0;

	if (!path)
		return (-1);
	for (i = 0; path[i]; i++)
	{
		if (i == 0 && path[i] == ':')
			return (0);
		if (path[i] == ':')
			index++;
		if (path[i] == ':' && path[i + 1] == ':')
			return (index);
		if (path[i] == ':' && path[i + 1] == 00)
			return (index);
	}
	return (-1);
}
