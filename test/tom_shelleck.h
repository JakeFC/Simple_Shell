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


extern char **environ;
int _strlen(char *str);
char *_strdup(char *str);
int word_count(char *str, char *del);
char **strtok_array_test(char *str, char *del);
char **strtok_array(char* str, char *del);
int parents_forking(char **args);
char *_getenv(const char *name);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_reallocf(void *ptr, unsigned int old_size, unsigned int new_size);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
char *_strcpy(char *dest, char *src);
int env_index(const char *name);
void path_finder(char ***args);
char *cmd_path(char *cmd, char *path);
char *cmd_cwd(char *cmd);


#endif /* TOM_SHELLECK_H */
