#include "tom_shelleck.h"

int main(void)
{
	node_t *head = NULL, *trav;
	int i;
	char **arr, *value;

	value = _getenv("PATH");
	if (!value)
		return (1);
	arr = strtok_array_test(value, ":");
	free(value);
	if (!arr)
		return (1);
	for (i = 0; arr[i]; i++)
	{
		add_node_end(&head, _strdup(arr[i]));
		free(arr[i]);
	}
	free(arr);
	trav = head;
	while (trav)
	{
		write(STDOUT_FILENO, trav->dir, _strlen(trav->dir));
		write(STDOUT_FILENO, "\n", 1);
		trav = trav->next;
	}
	free_node(head);
	return (0);
}

/**
 * add_node_end - adds a new node at the end of a listint_t list
 * @head: pointer to address of first node
 * @str: string data for new node
 * Return: address of the new element, or NULL
 */
node_t *add_node_end(node_t **head, char *str)
{
	node_t *new, *tmp;

	if (!head)
		return (NULL);
	new = malloc(sizeof(node_t));
	if (!new)
		return (NULL);
	new->dir = str;
	new->next = NULL;
	if (*head)
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*head = new;
	return (new);
}
/**
 * free_node - frees a node_t list
 * @head: pointer to first node of list
 */
void free_node(node_t *head)
{
	node_t *tmp;

	while (head)
	{
		tmp = head;
		free(head->dir);
		head = head->next;
		free(tmp);
	}
}
