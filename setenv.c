#include "tom_shelleck.h"
/**
 * malloc_array - mallocs an unmalloced array of pointers and its pointers
 * @arr: array input
 * Return: pointer to malloc'd array, or NULL on error
 */
char **malloc_array(char **arr)
{
	int i;

	if (!arr)
		return (NULL);
	for (i = 0; arr[i]; i++)
	{
		arr[i] = _realloc(arr[i], _strlen(arr[i]) + 1, _strlen(arr[i]) + 1);
		if (!arr[i])
		{
			for (; i >= 0; i--)
				free(arr[i]);
			return (NULL);
		}
	}
	arr = _realloc(arr, 8 * (i + 1), 8 * (i + 1));
	if (!arr)
		return (NULL);
	return (arr);
}
/**
 * _setenv - changes or adds an environment variable
 * @name: variable name
 * @value: variable value
 * Return: 3 on success, -1 on error
 */
int _setenv(const char *name, const char *value)
{
	int i, ii, size, start, psize;

	if (!environ || !name)
		return (-1);
	for (i = 0; name[i]; i++)
		if (name[i] == '=')
			return (-1);
	size = _strlen((char *)name) + _strlen((char *)value) + 2;
	start = _strlen((char *)name), psize = sizeof(char *);
	if (!_getenv(name))
	{
		for (i = 0; environ[i]; i++)
			;
		environ = _reallocf((void *)environ, (i + 1) * psize, (i + 2) * psize);
		environ[i] = malloc(sizeof(char) * size);
		if (!environ[i])
			return (-1);
		_strcpy(environ[i], (char *)name);
		environ[i][start++] = '=';
		for (ii = 0; start < size - 1; start++, ii++)
			environ[i][start] = value[ii];
		environ[i][start] = 00;
		environ[++i] = NULL;
		return (3);
	}
	if (!value || !value[0])
		return (3);
	if (_getenv(name) && value[0])
	{
		i = env_index(name);
		if (i < 0)
			return (3);
		free(environ[i]);
		environ[i] = malloc(sizeof(char) * size);
		if (!environ[i])
			return (-1);
		_strcpy(environ[i], (char *)name);
		environ[i][start++] = '=';
		for (ii = 0; start < size - 1; start++, ii++)
			environ[i][start] = value[ii];
		environ[i][start] = 00;
	}
	return (3);
}
/**
 * _realloc - reallocates a memory block without freeing the old
 * @ptr: pointer to previous memory allocation
 * @old_size: size, in bytes, of the spaces allocated to ptr
 * @new_size: size, in bytes, of the new memory block
 * Return: pointer to new memory block, or NULL if new_size is 0 and ptr is
 * not NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *s, *p;
	int i, ptrmax;

	if (new_size == 0 && ptr)
	{
		return (NULL);
	}
	if (!ptr)
	{
		s = malloc(new_size);
		if (!s)
			return (NULL);
		return (s);
	}
	s = malloc(new_size);
	if (!s)
		return (NULL);
	p = ptr;
	ptrmax = old_size > new_size ? new_size : old_size;
	for (i = 0; i < ptrmax; i++)
		s[i] = p[i];
	return (s);
}
/**
 * _reallocf - reallocates a memory block
 * @ptr: pointer to previous memory allocation
 * @old_size: size, in bytes, of the spaces allocated to ptr
 * @new_size: size, in bytes, of the new memory block
 * Return: pointer to new memory block, or old pointer if sizes are the same,
 * or NULL if new_size is 0 and ptr is not NULL
 */
void *_reallocf(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *s, *p;
	int i, ptrmax;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
	{
		s = malloc(new_size);
		if (!s)
			return (NULL);
		return (s);
	}
	s = malloc(new_size);
	if (!s)
		return (NULL);
	p = ptr;
	ptrmax = old_size > new_size ? new_size : old_size;
	for (i = 0; i < ptrmax; i++)
		s[i] = p[i];
	free(ptr);
	return (s);
}
