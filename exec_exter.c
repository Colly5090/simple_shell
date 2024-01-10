#include "main.h"
/**
 * exec_external - function to execute external commands
 * @args: command to be executed
 * @path: path of the command to execute
 * Return: nothing
*/
void exec_external(char **args, char *path)
{
	pid_t childPid, wpid;
	int status;

	if (path == NULL)
	{
		perror("./shell");
		return;
	}

	childPid = fork();
	if (childPid == 0)
	{
		if (execv(path, args) == -1)
		{
			perror("./shell: execv: ");
			exit(EXIT_FAILURE);
		}
	}
	else if (childPid < 0)
	{
		perror("./shell: fork: ");
	}
	else
	{
		do {
			wpid = waitpid(childPid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	(void)wpid;
	fflush(stdout);
}
