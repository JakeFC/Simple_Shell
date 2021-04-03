#ifndef TOM_SHELLECK_H
#define TOM_SHELLECK_H
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>


typedef struct node
{
	char *dir;
	struct node *next;
} node_t;
int _strlen(char *str);
char *_strdup(char *str);
int word_count(char *str, char *del);
char **strtok_array_test(char *str, char *del);
char **strok_array(char* str);
int parents_forking(char **args);
char *_getenv(const char *name);
node_t *add_node_end(node_t **head, char *str);
void free_node(node_t *head);

#endif /* TOM_SHELLECK_H */
