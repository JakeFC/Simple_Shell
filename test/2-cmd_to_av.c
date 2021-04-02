#include "tom_shelleck.h"

/**
 * word_count - counts the number of words in a string
 * @str: string input
 * @del: word delimiter
 * Return: number of words, or 0 on failure
 * Description: uses the number of valid strtok calls on a duplicate string
 * to count how many separate words there are in the original
 */
int word_count(char *str, char *del)
{
	int wordcount = 0;
	char *sdup, *token;

	if (!str || !del)
		return (0);
	sdup = _strdup(str);
	if (!sdup)
		return (0);
	token = strtok(sdup, del);
/* if the previous token value wasn't NULL, increment wordcount and token */
	while (token)
	{
		wordcount++;
/* successive calls to strtok requre NULL as first field */
		token = strtok(NULL, del);
	}
	free(sdup);
	return (wordcount);
}
/**
 * strtok_array - splits a string and returns an array of each word
 * @str: string input
 * @del: word delimiter
 * Return: array of tokens ending in a NULL pointer, or NULL on error
 * Description: uses word_count to dynamically allocate for the number of
 * pointers needed, adding one for a NULL terminator, and _strdup to copy
 * each strtok result into the array
 */
char **strtok_array(char *str, char *del)
{
	char **arr;
	int i;
	char *token;

	if (!str || !del)
		return (NULL);
/* we need a pointer for each word, plus a NULL pointer to end the array */
	arr = malloc(sizeof(char *) * (word_count(str, del) + 1));
	if (!arr)
		return (NULL);
	token = strtok(str, del);
	for (i = 0; token; i++)
	{
/* set each index to a word, in order */
		arr[i] = _strdup(token);
		if (!arr[i])
		{
/* make sure to free each previous index on error */
			for (i-- ; i >= 0; i--)
				free(arr[i]);
			free(arr);
			return (NULL);
		}
		token = strtok(NULL, del);
	}
	arr[i] = NULL;
	return (arr);
}
