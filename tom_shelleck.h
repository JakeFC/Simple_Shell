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
int _getline(char *shell);
int _strlen(char *str);
char *_strdup(char *str);
int word_count(char *str, char *del);
char **strtok_array_test(char *str, char *del);
char **strtok_array(char *str, char *del);
int parents_forking(char **args, char *shell);
char *_getenv(const char *name);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_reallocf(void *ptr, unsigned int old_size, unsigned int new_size);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
char *_strcpy(char *dest, char *src);
int env_index(const char *name);
void path_finder(char **args);
char *cmd_path(char *cmd, char *path);
char *cmd_cwd(char *cmd);
int slash_specified(char *str);
int empty_path_check(char *path);
int string_switch(char **prev,char **tmp);
int exit_checker(char **args, char *shell);
int _atoi(char *s);
char *str_concat(char *s1, char *s2);
int perror_exit(char *arg, char *shell);
int _strcmp(char *s1, char *s2);
int free_array(char **arr);
int perror_execve(char *arg, char *shell);


#endif /* TOM_SHELLECK_H */
