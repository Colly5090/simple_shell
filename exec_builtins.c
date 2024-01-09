#include "main.h"
/**
 * exec_built_ins - function to execute built-in commands
 * @args: array of commands to be executed
 * Return: nothing
*/
void exec_built_ins(char *args[]);
void exec_built_ins(char *args[])
{
	char cwd[1024];
	const char *dir = (args && args[1]) ? args[1] : NULL;
	const char *oldpwd = getenv("OLDPWD");
	int status = 0;

	if (args == NULL || args[0] == NULL)
	{
		perror("./shell Error: Cd can't be NULL");
		return;
	}
	if (_strcmp(args[0], "cd") == 0)
	{
		if (!dir || _strcmp(dir, "~") == 0)
			dir = getenv("HOME");
		else if	(_strcmp(dir, "-") == 0)
		{
			if (oldpwd)
			{
				dir = oldpwd;
			}
			else
			{
				write(1, "./shell cd: OLDPWD not set\n", 28);
				return;
			}
		}
		dir = getenv("OLDPWD");
	if (!dir || chdir(dir) != 0)
		perror("./shell Error Cd not working");
	else if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		/*printf("Current directory: %s\n", cwd);*/
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	else
		perror("./shell getcwd");
	}
	else if (_strcmp(args[0], "pwd") == 0)
	{
		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			write(1, cwd, _strlen(cwd));
			write(1, "\n", 1);
		} else
			perror("./shell getcwd");
	} else if (_strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
			status = atoi(args[1]);
		exit(status);
		/*if (WIFEXITED(status))*/
			/*exit(WEXITSTATUS(status));*/
		/*else if (WIFSIGNALED(status))*/
			/*exit(WTERMSIG(status));*/
		/*else*/
			/*exit(1);*/
	}
		/*exit(dir ? atoi(dir) : 0);*/
	else
	{
		write(1, "./shell Invalid", 16);
		write(1, args[0], _strlen(args[0]));
		write(1, "\n", 1);
	}
}
