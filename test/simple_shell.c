#include "tom_shelleck.h"

/**
 * path_finder - appends the correct directory to the first command string
 * @args: address to array of argument strings
 */
void path_finder(char ***args)
{
	int i;
	char **path_tkn;
	char *tmp;

/* create a token array for PATH value */
	tmp = _getenv("PATH");
	path_tkn = (strtok_array(tmp, ":"));
	free(tmp);
/* Is first argument in any PATH directory? Change arg[0] to full path if so */
	for (i = 0; path_tkn[i]; i++)
	{
		tmp = cmd_path(*args[0], path_tkn[i]);
		if (tmp != NULL)
		{
			free(*args[0]);
			*args[0] = _strdup(tmp);
			break;
		}
	}
/* free PATH token array */
	for (i = 0; path_tkn[i]; i++)
		free(path_tkn[i]);
	free(path_tkn);
/* if argument wasn't found in PATH, check current directory */
	if (tmp != NULL)
	{
/* Is first argument in current directory? Change arg[0] to full path if so */
		tmp = cmd_cwd(*args[0]);
		if (tmp != NULL)
		{
			free(*args[0]);
			*args[0] = _strdup(tmp);
		}
	}
	free(tmp);
}
/**
 * parents_forking - runs the array of command tokens given
 * @args: array of command tokens
 * Return: 0 on success, or 1 on error
 */
int parents_forking(char **args)
{
	int child, status, waitv, i;

	path_finder(&args);
	child = fork();
/* if we're in the child process */
	if (child == 0)
/* run arguments and print error msg on error */
		if (execve(args[0], args, NULL) == -1)
		{
			perror("./hsh");
			for (i = 0; args[i]; i++)
				free(args[i]);
			free(args);
			_exit(1);
		}
/* make parent wait for child to exit and check for error before continuing */
	waitv = waitpid(child, &status, 0);
	if (waitv == -1)
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
 * @del: word delimeter string
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
	size_t len = 120;
	char *buf = malloc(sizeof(char) * len);
	ssize_t getlen;

	write(STDOUT_FILENO, "$ ", 2);
/* run getline to wait for stdin and place in buffer */
	while ((getlen = getline(&buf, &len, stdin)) != -1)
	{
/* if no error, change the newline to NULL byte in buf string */
		buf[getlen - 1] = 00;
/* pass the argument array created by strtok_array to cmd executer */
		parents_forking(strtok_array(buf, " "));
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
	}
	if (getlen == EOF)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(buf);
		return (0);
	}
	perror("./hsh");
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buf);
	return (1);
}
