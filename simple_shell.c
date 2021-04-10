#include "tom_shelleck.h"

/**
 * path_finder - appends the correct directory to the first command string
 * @args: address to array of argument strings
 */
void path_finder(char **args)
{
	int i, cwdi;
	char **path_tkn;
	char *tmp;

/* create a token array for PATH value */
	tmp = _getenv("PATH");
/* if an empty PATH value field is found, this is the index before */
	cwdi = empty_path_check(tmp);
	path_tkn = (strtok_array(tmp, ":"));
	free(tmp);
/* Is first argument in any PATH directory? Change arg[0] to full path if so */
	for (i = 0; path_tkn[i]; i++)
	{
		if (i == cwdi)
		{
			tmp = cmd_cwd(args[0]);
			if (tmp != NULL)
			{
				string_switch(&args[0], &tmp);
				break;
			}
		}
		tmp = cmd_path(args[0], path_tkn[i]);
		if (tmp != NULL)
		{
			string_switch(&args[0], &tmp);
			break;
		}
	}
	if (!tmp && i == cwdi)
	{
		tmp = cmd_cwd(args[0]);
		if (tmp != NULL)
			string_switch(&args[0], &tmp);
	}
/* free PATH token array */
	for (i = 0; path_tkn[i]; i++)
		free(path_tkn[i]);
	free(path_tkn);
	free(tmp);
}
/**
 * parents_forking - runs the array of command tokens given
 * @args: address of array of command tokens
 * @shell: shell executable name
 * Return: 0
 */
int parents_forking(char **args, char *shell)
{
	int child, status, waitv;

	if (!args)
		return (0);
/* if directory of command not specified, search PATH and edit args[0] */
	if (!slash_specified(args[0]))
		path_finder(args);
	child = fork();
/* if we're in the child process */
	if (child == 0)
	{
/* run arguments and print error msg on error */
		if (execve(args[0], args, environ) == -1)
			perror(shell);
		_exit(0);
	}
/* make parent wait for child to exit and check for error before continuing */
	waitv = waitpid(child, &status, 0);
	if (waitv == -1)
		perror("Wait");
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
 * _getline - takes arguments from cmd line and runs them
 * @shell: name of the shell executable
 * Return: 0, or the exit command argument if given
 */
int _getline(char *shell)
{
	size_t len = 0;
	ssize_t getlen;
	char *buf = NULL, **args;
	int exit_check, exit_code = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
/* run getline to wait for stdin and place in buffer */
	while ((getlen = getline(&buf, &len, stdin)) != -1)
	{
/* if no error, change the newline to NULL byte in buf string */
		if (buf[getlen - 1] == '\n')
			buf[getlen - 1] = 00;
		args = strtok_array(buf, " ");
		exit_check = exit_checker(args, shell);
		if (exit_check == 1)
		{
			if (args[1])
				exit_code = _atoi(args[1]);
			free_array(args);
			free(buf);
			return (exit_code);
		}
		if (exit_check != 2)
/* pass the argument array created by strtok_array to cmd executer */
			parents_forking(args, shell);
		free_array(args);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
	}
	free(buf);
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
