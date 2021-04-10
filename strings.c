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
/**
 * str_concat - creates a copy of s1 with s2 added to the end
 * @s1: string input
 * @s2: second string input
 * Return: pointer to new string, or 0 if insufficient memory
 */
char *str_concat(char *s1, char *s2)
{
	char *c;
	unsigned int a, b, i, ii;

	if (s1 == NULL)
		a = 0;
	else
		for (a = 0; s1[a] != 00;)
			a++;
	if (s2 == NULL)
		b = 0;
	else
		for (b = 0; s2[b] != 00;)
			b++;
	c = malloc(a + b + 1);
	if (c == NULL)
		return (0);
	for (i = 0; i < a; i++)
		c[i] = s1[i];
	for (ii = 0; i < (a + b); i++, ii++)
		c[i] = s2[ii];
	c[i] = 00;
	return (c);
}
/**
 * _strcmp - compares strings for equality
 * @s1: string input to compare
 * @s2: string input to compare to
 * Return: ascii value difference of first different index
 * (s1[i] - s2[i]), or 0 if none
 */
int _strcmp(char *s1, char *s2)
{
	int a;

	for (a = 0; s1[a] == s2[a] && s1[a] != '\0' && s2[a] != '\0';)
		a++;
	return (s1[a] - s2[a]);
}
