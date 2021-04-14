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
#include <limits.h>
#include <errno.h>
#include <signal.h>


extern int errno;
extern char **environ;
int _getline(char *shell);
int _strlen(char *str);
char *_strdup(char *str);
int word_count(char *str, char *del);
char **strtok_array_test(char *str, char *del);
char **strtok_array(char *str, char *del);
int parents_forking(char **args, char *shell, int line);
char *_getenv(const char *name);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_reallocf(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strcpy(char *dest, char *src);
int env_index(const char *name);
void path_finder(char **args);
char *cmd_path(char *cmd, char *path);
char *cmd_cwd(char *cmd);
int slash_specified(char *str);
int empty_path_check(char *path);
int string_switch(char **prev, char **tmp);
int builtin_checker(char **args, char *shell, int line, int *errcode);
long int _atoli(char *s);
char *str_concat(char *s1, char *s2);
int perror_exit(char *arg, char *shell, int line);
int perror_notfound(char *arg, char *shell, int line);
char *error_input(char *arg, char *shell, int line);
int _strcmp(char *s1, char *s2);
int free_array(char **arr);
char *_itoa(int n);
char **malloc_array(char **arr);
void _handler(int sig);
int _unsetenv(const char *name);
int _setenv(const char *name, const char *value);
int _printenv(void);


#endif /* TOM_SHELLECK_H */
