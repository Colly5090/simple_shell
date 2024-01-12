#include "main.h"
/**
 * exec_non_interactive - A function to execute commands in non-interactively
 * @args: command to be executed
 * @path: path of the command to be executed
 * Return: nothing
 */
void exec_non_interactive(char **args, char *path);
void exec_non_interactive(char **args, char *path)
{
	pid_t childPid, wpid;
	int status;

	if (path == NULL)
	{
		perror("./shell ");
		return;
	}

	childPid = fork();
	if (childPid == 0)
	{
		if (execv(path, args) == -1)
		{
			perror("./shell execv: ");
			exit(EXIT_FAILURE);
		}
	}
	else if (childPid < 0)
		perror("./shell fork: ");
	else
	{
		do {
			wpid = waitpid(childPid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));

		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) == 0)
				exit(0);
			else
				exit(1);
		}
	else if (WIFSIGNALED(status))
		exit(1);
	else
		exit(1);
	}

	(void)wpid;
	fflush(stdout);
}
