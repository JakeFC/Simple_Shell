#include "tom_shelleck.h"

extern char **environ;

char *_getenv(const char *name)
{
	int i, ii, ni, count, start;
	char *value;

	for (i = 0; environ[i]; i++)
                for (ni = 0, ii = 0; name[ni] && environ[i][ii]; ni++, ii++)
                {
                        if (environ[i][ii] != name[ni])
                                break;
                        if (environ[i][ii + 1] == '=' && !name[ni + 1])
			{
				start = ii + 2;
				for (ii += 2, count = 0; environ[i][ii]; ii++)
					count++;
				value = malloc(sizeof(char) * count + 1);
				if (!value)
					return (NULL);
				for (ii = 0; environ[i][start]; start++, ii++)
					value[ii] = environ[i][start];
				value[ii] = 00;
				return (value);
			}
		}
	return (NULL);
}

/**
 * env_index: finds the index in environ global variable where name is found
 * @name: environmental variable
 * Return: index of environ where name is found, or -1 if not
 */
int env_index(const char *name)
{
	int i, ii, ni;

	for (i = 0; environ[i]; i++)
                for (ni = 0, ii = 0; name[ni] && environ[i][ii]; ni++, ii++)
                {
                        if (environ[i][ii] != name[ni])
                                break;
                        if (environ[i][ii + 1] == '=' && !name[ni + 1])
				return (i);
		}
	return (-1);
}
