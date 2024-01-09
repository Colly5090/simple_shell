#include "main.h"
/**
 * my_setenv - function to handle setenv
 * @name: name of the environment variable
 * @value: value to set env
 * Return: 0 on success -1 failed
*/
int my_setenv(const char *name, const char *value)
{
	int store;
	const int check = 1;

	store = setenv(name, value, check);
	if (store == -1)
	{
		perror("./shell: Failed to set environment variable");
		return (-1);
	}
	return (0);
}

/**
 * my_unsetenv - function to unset environment variables
 * @name: name of the environment variable to unset
 * Return: 0 on success -1 failed
*/
int my_unsetenv(const char *name)
{
	int result;

	result = unsetenv(name);
	if (result == -1)
	{
		perror("./shell: Failed to unset environment variables");
		return (-1);
	}
	return (0);
}
