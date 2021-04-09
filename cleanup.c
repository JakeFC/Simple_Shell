#include "tom_shelleck.h"

/**
 * string_switch - frees a string and replaces it with another
 * @prev: address of string to replace
 * @new: address of string to place into prev address
 * Return: 0 on success, 1 on failure
 */
int string_switch(char **prev,char **tmp)
{
	free(*prev);
	*prev = _strdup(*tmp);
	if (!*prev)
		return (1);
	return (0);
}
