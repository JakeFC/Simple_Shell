#include "tom_shelleck.h"
/**
 * _setenv - changes or adds an environment variable
 * @name: variable name
 * @value: variable value
 * @overwrite: int value associated with overwrite behavior
 * Return: 0 on success, -1 on failure
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	int i, ii, size, start;

	if (!environ || !name)
		return (-1);
	size = _strlen((char *)name) + _strlen((char *)value) + 2;
	start = _strlen((char *)name);
	if (_getenv(name) && overwrite)
	{
		i = env_index(name);
		if (i < 0)
			return (-1);
		environ[i] = malloc(sizeof(char) * size);
		if (!environ[i])
			return (-1);
		_strcpy(environ[i], (char *)name);
		environ[i][start++] = '=';
		for (ii = 0; start < size - 1; start++, ii++)
			environ[i][start] = value[ii];
		environ[i][start] = 00;
		return (0);
	}
	if (!_getenv(name))
	{
		for (i = 0; environ[i]; i++)
			;
		environ = _realloc((void *)environ, (i + 1) * 8, (i + 2) * 8);
		environ[i] = malloc(sizeof(char) * size);
		_strcpy(environ[i], (char *)name);
		environ[i][start++] = '=';
		for (ii = 0; start < size - 1; start++, ii++)
			environ[i][start] = value[ii];
		environ[i][start] = 00;
		environ[++i] = NULL;
	}
	return (0);
}
/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to previous memory allocation
 * @old_size: size, in bytes, of the spaces allocated to ptr
 * @new_size: size, in bytes, of the new memory block
 * Return: pointer to new memory block, or old pointer if sizes are the same,
 * or NULL if new_size is 0 and ptr is not NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *s, *p;
	int i, ptrmax;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
/* free(ptr); */
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
/*	free(ptr);*/
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
