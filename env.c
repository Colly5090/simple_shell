#include "main.h"
/**
 * env_var - function to handle env
 * Return: nothing
*/
void env_var(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
