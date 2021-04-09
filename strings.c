#include "tom_shelleck.h"

/**
 * _strlen - gives the length of a string, minus NULL byte
 * @str: string input
 * Return: number of characters before NULL byte
 */
int _strlen(char *str)
{
	int i = 0;

	if (str)
		while (str[i])
			i++;
	return (i);
}
/**
 * _strdup - creates and returns a pointer to a copy of the inputted string
 * @str: string input
 * Return: pointer to copy of str, or NULL if str is NULL or there is
 * insufficient memory
 */
char *_strdup(char *str)
{
	char *s;
	int i, l;

	if (str == NULL)
		return (NULL);
	for (l = 0; str[l] != '\0';)
		l++;
	s = malloc(l + 1);
	if (s == NULL)
		return (NULL);
	for (i = 0; i <= l; i++)
		s[i] = str[i];
	return (s);
}
/**
 * _strcpy - copies a string to another variable
 * @dest: destination variable
 * @src: string source
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int a;

	for (a = 0; src[a] != '\0'; a++)
		dest[a] = src[a];
	dest[a] = '\0';
	return (dest);
}
