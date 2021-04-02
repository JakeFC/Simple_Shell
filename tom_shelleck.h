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


int _strlen(char *str);
char *_strdup(char *str);
int word_count(char *str, char *del);
char **strtok_array(char *str, char *del);


#endif /* TOM_SHELLECK_H */
