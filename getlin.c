#include "main.h"
/**
 * read_input - function to read input from user
 * Return: nothing
*/
char *read_input(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t read_line;

	read_line = getline(&lineptr, &n, stdin);
	if (read_line == -1)
	{
		/*write(1, "\n", 1);*/
		/*return NULL;*/
		if (lineptr != NULL) /*edited*/
		{
			free(lineptr);
			exit(EXIT_FAILURE);
		}
	}
	/*free(lineptr);*/
	return (lineptr);
}
