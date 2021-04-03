#include "tom_shelleck.h"

/**
 * parents_forking - runs the array of command tokens given
 * args: array of command tokens
 * Return: 0
 */
int parents_forking(char **args)
{
	int child, status, waitv, i;

	child = fork();
/* if we're in the child process */
	if (child == 0)
/* run arguments and print error msg on error */
		if (execve(args[0], args, NULL) == -1)
			perror("Ececve");
/* make parent wait for child to exit and check for error before continuing */
	if ((waitv = waitpid(child, &status, 0)) == -1)
		perror("Wait");
	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);
	return (0);
}

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
 * Return: array of tokens ending in a NULL pointer, or NULL on error
 * Description: uses word_count to dynamically allocate for the number of
 * pointers needed, adding one for a NULL terminator, and _strdup to copy
 * each strtok result into the array
 */
char **strtok_array(char *str)
{
	char **arr;
	int i;
	char *token;
	char *del = " ";

	if (!str)
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

/**
 * main - takes arguments from cmd line and runs them
 * Return: 0, or 1 on error
 */
int main(void)
{
	size_t len = 1024;
	char *buf = malloc(sizeof(char) * len);
	ssize_t getlen;

	if (!buf)
		return (1);
	printf("$ ");
/* run getline to wait for stdin and place in buffer */
	if ((getlen = getline(&buf, &len, stdin)) != -1)
	{
/* if no error, change the newline to NULL byte in buf string */
		buf[getlen - 1] = 00;
/* pass the argument array created by strtok_array to cmd executer */
		parents_forking(strtok_array(buf));
	}
	free(buf);
	return (0);
}
