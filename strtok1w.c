#include "main.h"
/**
 * token_input - function to tokenize user inputs
 * @input: input from users to be tokenized
 * Return: pointer to the new tokens
*/
char **token_input(char *input);
char **token_input(char *input)
{
	char **new_strings = NULL, *token;
	int numoftoken = 0;
	int x = 0;
	const char *delim = " ";
	char *copy_lineptr = strdup(input);

	if (copy_lineptr == NULL)
	{
		free(copy_lineptr); /* edited*/
		perror("./shell: Memory Error");
		exit(EXIT_FAILURE);
	}
	token = _strtok(copy_lineptr, delim);
	while (token != NULL)
	{
		numoftoken++;
		token = _strtok(NULL, delim);
	}
	new_strings = malloc(sizeof(char *) * (numoftoken + 1));
	if (new_strings == NULL)
	{
		free(copy_lineptr);
		/*perror("./shell: Memory Error");*/
		/*exit(EXIT_FAILURE);*/
		return (NULL);
	}
	token = _strtok(input, delim);
	while (token != NULL)
	{
		new_strings[x] = strdup(token);
		if (new_strings[x] == NULL)
		{
			/*free(new_strings[x]);*//*edited*/
			perror("./shell: Memory Error");
			exit(EXIT_FAILURE);
		}
		token = _strtok(NULL, delim);
		x++;
	}
	/*new_strings[x] = NULL;*//*edited*/
	free(copy_lineptr);
	new_strings[x] = NULL;
	/*for (i = 0; i < x; i++)*/
		/*free(new_strings[i]);*/
	/*free(input);*//*edited*/
	return (new_strings);
}
