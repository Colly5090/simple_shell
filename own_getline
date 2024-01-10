#include "main.h"
/**
 * _getline - function to create a custom getline
 * @lineptr: input string from user with memory for storage
 * @n: number of strings from the user
 * @stream: a buffer to store all input from user
 * Return: 0 on success and -1 on failure
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t i = 0, new_size;
	int c;
	char *new_line;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}

	while ((c = fgetc(stream)) != EOF)
	{
		if (i >= *n - 1)
		{
			new_size = *n * 2;
			new_line = realloc(*lineptr, new_size);
			if (new_line == NULL)
			{
				free(*lineptr);
				return (-1);
			}
			*lineptr = new_line;
			*n = new_size;
		}
		(*lineptr)[i++] = (char)c;

		if (c == '\n')
		{
			(*lineptr)[i] = '\0';
			return (i);
		}
	}
	if (i > 0)
	{
		(*lineptr)[i] = '\0';
		return (i);
	}
	return (-1);
}
