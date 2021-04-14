#include "tom_shelleck.h"

/**
 * getline_file - takes arguments from a file and runs them
 * @shell: name ofthe shell executable
 * @file: file path given
 * Return: 0, or the exit command argument if given
 */
int getline_file(char *shell, char *file)
{
        size_t len = 0;
        ssize_t getlen;
        char *buf = NULL, **args = NULL;
        int exit_check = 0, exit_code = 0, line = 1, errcode = 0;

/* run getline to wait for stdin and place in buffer */
        while ((getlen = getline(&buf, &len, file)) != -1)
        {
/* if no error, change the newline to NULL byte in buf string */
                if (buf[getlen - 1] == '\n')
                        buf[getlen - 1] = 00;
                args = strtok_array(buf, " ");
                exit_check = builtin_checker(args, shell, line, &errcode);
                if (exit_check == 2)
                {
                        exit_code = _atoli(args[1]), free_array(args);
                        free_array(environ), free(buf);
                        return (exit_code);
                }
                if (exit_check == 0)
/* pass the argument array created by strtok_array to cmd executer */
                        errcode = parents_forking(args, shell, line);
                free_array(args);
                if (exit_check == 1)
                        break;
		line++;
        }
        free_array(environ), free(buf);
        if (exit_check != 1)
                write(STDOUT_FILENO, "\n", 1);
        return (errcode);
}
