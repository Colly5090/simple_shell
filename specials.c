#include "main.h"
/**
 * separator - function to check command separators
 * @input: the commands entered by user
 * Return: nothing
 */
void separator(const char *input)
{
	char *inputCopy;
	char *tokens;
	int status_code;

	inputCopy = strdup(input);
	if (inputCopy == NULL)
	{
		perror("./shell: memory error");
		return;
	}

	tokens = _strtok(inputCopy, ";");
	while (tokens != NULL)
	{
		status_code = system(tokens);

		if (status_code == -1)
			perror("./shell: bad command");
	       tokens = _strtok(NULL, ";");
	}
	free(inputCopy);
}
