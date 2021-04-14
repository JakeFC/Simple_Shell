#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
extern char** environ;
// Driver code
int main(void)
{
	pid_t pid = fork();
	char *arr[] = {"/bin/ls", "-l", "./nopath", NULL};
      
	if ( pid == 0 )
	{
		/* The pathname of the file passed to execl()
		   is not defined   */
		if (execve(arr[0], arr, environ) == -1)
			perror("execve");
		_exit(0);
	}
  
	int status;
      
	int check = waitpid(pid, &status, 0);
	if (check == -1)
		perror("waitpid");
	if ( WIFEXITED(status) )
	{
		int exit_status = WEXITSTATUS(status);        
		printf("Exit status of the child was %d\n", 
		       exit_status);
	}
	return 0;
}
