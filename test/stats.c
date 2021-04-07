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
	buf = _strcpy(buf, path);
/* start buffer index at end of directory name, replacing NULL byte with '/' */
        bi = _strlen(buf);
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
