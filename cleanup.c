#include "tom_shelleck.h"
/**
 * string_switch - frees a string and replaces it with another
 * @prev: address of string to replace
 * @tmp: address of string to place into prev address
 * Return: 0 on success, 1 on failure
 */
int string_switch(char **prev, char **tmp)
{
	free(*prev);
	*prev = _strdup(*tmp);
	if (!*prev)
		return (1);
	return (0);
}
/**
 * free_array - frees an array of pointers
 * @arr: address of array of pointers
 * Return: 0 on success, 1 for failure
 */
int free_array(char **arr)
{
	int i;

	if (!arr)
		return (1);
	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
	return (0);
}
