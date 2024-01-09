#include "main.h"
/**
 * _strtok - A function to break strings into tokens
 * @str: string to be tokenized
 * @sep: delimeter used for the tokenization
 * Return: null pointer
 */
char *_strtok(char *str, const char *sep)
{
	static char *lastToken;
	char *tokenStart;

	if (str != NULL)
	{
		lastToken = str;
	}
	else
	{
		if (lastToken == NULL)
			return (NULL);
	}

	lastToken += _strspn(lastToken, sep);/*here*/

	if (*lastToken == '\0')
	{
		lastToken = NULL;
		return (NULL);
	}
	tokenStart = lastToken;

	lastToken += strcspn(lastToken, sep);

	if (*lastToken != '\0')
	{
		*lastToken = '\0';
		lastToken++;
	}
	else
	{
		lastToken = NULL;
	}
	return (tokenStart);
}
